%{
    #include "TablaSimbolos.h"
%}

%{
    lista* tablaSim; //Declarar la estructura a usar
    char ans[1000]; //Cadena auxiliar para convertir a string y operaciones con cadenas (obtener memoria para la nueva cadena)

    //Funcion que concatena cadenas, 
    char * concat(char * a, char * b) { 
        strcpy(ans, ""); 
        strcat(ans,  a); 
        strcat(ans,  b); 
        return strdup(ans); //regresa la direccion de la memoria reservada
    }
    //Funcion que resta cadenas
    char * remstr(char * a, char * b) {
        char *  x = strstr(a, b); //Retorna un apuntador a la posicion de la cadena b en a 
        if (!x) return strdup(a); //Si no existe la cadena b en a, regresa la dir mem para a
        int k = x - a, i = 0; //Operacion con apuntadores que nos da la posicion de la cadena
        int m =    strlen(b); 
        strcpy(ans, "");
        for (i = 0; i <= k; i++) //Almacenar los caracteres a la izquierda
        ans[i]   =  a[i];
        ans[i - 1] =  '\0';
        strcat(ans, x + m); //Almacenar los caracteres a la derecha de la cadena b en la cadena a
        return strdup(ans);
    }
%}
%union{
    int Int;
    double Double;
    char* String;
}
//Token usados para identificar los tipos de datos.
%token tipoInt 
%token tipoDouble 
%token tipoString 
//Token usados para los valores de los datos
%token <Int> valorInt 
%token <Double> valorDouble
%token <String> valorString
//Gramaticas para las expresiones
%type <Int> expInt 
%type <Double> expDouble 
%type <String> expString
//Token usados para verificar existencias en la tabla de simbolos.
%token <String>  intDeclarado
%token <String>  varNoDecla
%token <String>  doubleDeclarado
%token <String>  stringDeclarado
//Tipos usados para declarar variables y para manejo de errores.
%type <String> declaracion
%type <String> errorAsignaTip
%type <String> errorOpTipo
//Definir precedencia
%left '+' '-' 
%left '/' '*' '%'
%left '^' 
%left '='

%%
input:    /* cadena vacía */
        | input line             
;

line:     '\n'
        | expInt '\n'  { printf ("\t\tResultado: %d\n", $1); } //Muestra el resultado en forma entera (match)
        | expDouble '\n'  { printf ("\t\tResultado: %f\n", $1); } //Muestra el resultado en forma double (match)
        | expString '\n'  { printf ("\t\tResultado: %s\n", $1); } //Muestra las operaciones con expresiones string (match)
        | declaracion '\n'  { printf ("\t\t%s \n",$1); } //Usado para empatar la gramatica de una declaracion
        | asignacion '\n'  { printf ("\t\tAsignacion \n"); } //Empata la gramatica de una asignacion
        | errorAsignaTip '\n'  { printf ("\t\tError: Asignacion de tipos \n"); } //Maneja los errores de asignacion de tipos e.g. string=int
        | errorOpTipo '\n'  { printf ("\t\tError: Tipos incompatibles \n"); } //Maneja los errores de operaciones con tipos e.g. string+int
        | errorVarDefinida '\n'  { printf ("\t\tError: Variable no definida\n"); } 
        | errorRedifincion '\n'  { printf ("\t\tError: Redifinicion no permitida\n"); }
;
//Reglas de produccion para la gramtica de operaciones con enteros.
expInt:     valorInt                       { $$ = $1; }
            | expInt '+' expInt          { $$ = $1 + $3; }
            | expInt '-' expInt          { $$ = $1 - $3; }
            | expInt '*' expInt          { $$ = $1 * $3; }
            | expInt '%' expInt          { $$ = $1 % $3; }
            | expInt '/' expInt          { $$ = $1 / $3; }
            | expInt '^' expInt          { $$ = pow($1,$3); }
            | '(' expInt ')'             { $$ = $2; }
            | '-' expInt                 { $$ = -$2;}
            | '+' expInt                 { $$ = $2;}
            | intDeclarado                      { $$ =  atoi(search(tablaSim, $1)->valor); } //Si yytext es una variable y esta ya está definida aquí se obtiene su valor.
;

//Reglas de produccion para la gramtica de operaciones con double
expDouble:  valorDouble                    { $$ = $1; }
            | expDouble '+' expDouble    { $$ = $1 + $3; }
            | expDouble '-' expDouble    { $$ = $1 - $3; }
            | expDouble '*' expDouble    { $$ = $1 * $3; }
            | expDouble '/' expDouble    { $$ = $1 / $3; }
            | expDouble '%' expDouble    { $$ = fmodf($1,$3); }
            | expDouble '^' expDouble    { $$ = pow($1, $3); }
            | expInt '^' expDouble       { $$ = pow($1, $3); }
            | expInt '%' expDouble       { $$ = fmodf($1,$3); }
            | expInt '+' expDouble       { $$ = $1 + $3; }      
            | expInt '-' expDouble       { $$ = $1 - $3; }
            | expInt '*' expDouble       { $$ = $1 * $3; }
            | expInt '/' expDouble       { $$ = $1 / $3; }
            | expDouble '+' expInt       { $$ = $1 + $3; }
            | expDouble '-' expInt       { $$ = $1 - $3; }
            | expDouble '*' expInt       { $$ = $1 * $3; }
            | expDouble '/' expInt       { $$ = $1 / $3; }
            | expDouble '%' expInt       { $$ = fmodf($1,$3); }
            | expDouble '^' expInt       { $$ = pow($1, $3); }
            | '(' expDouble ')'          { $$ = $2; } //Solo recupera el token entre parentesis.
            | '-' expDouble              { $$ = -$2;}
            | doubleDeclarado                   { $$ =  atof(search(tablaSim, $1)->valor); } //Si yytext es una variable ya definida (esta en TS) aquí recuperamos su valor
;

//Reglas de produccion para la gramatica de cadenas
expString:  valorString                   { $$ = $1;             }  
            | expString '+' expString   { $$ = concat($1, $3); }
            | expString '-' expString   { $$ = remstr($1, $3); }
            | '('    expString     ')'  { $$ = $2;             }
            | stringDeclarado                  { $$ = search(tablaSim,  $1)->valor; } //Si yytext es una variable y ya está en TS entonces recuperamos su valor(apuntador).
;
//Reglas de produccion para realizar una declaracion de variable, se usa varNoDecla cuando no existe en TS o su tipo de dato cuando se crea.
declaracion:  tipoInt  varNoDecla '=' expInt     ';'    {    
                                                            sprintf(ans,  "%d", $4); 
                                                            insert(tablaSim, "Int", $2, ans);
                                                            sprintf(ans,"Tipo de declaracion: tipo entero / nombre de variable / = / expresionInt / ;\n");
                                                            $$ = ans;
                                                       }
        | tipoString   varNoDecla '=' expString  ';'    {    
                                                            insert(tablaSim, "string",  $2,   $4); 
                                                            sprintf(ans,"Tipo de declaracion: tipo string / nombre de variable / = / expresionStr / ;\n");
                                                            $$ = ans;
                                                       }
        | tipoDouble   varNoDecla '=' expDouble  ';'    {    
                                                            sprintf(ans,  "%f", $4); 
                                                            insert(tablaSim, "double", $2, ans);
                                                            sprintf(ans,"Tipo de declaracion: tipo double / nombre de variable / = / expresionDouble / ;\n");
                                                            $$ = ans;
                                                       }
        | tipoInt  varNoDecla                    ';'    {    
                                                            insert(tablaSim, "Int", $2,  "0"); 
                                                            sprintf(ans,"Tipo de declaracion: tipo entero / nombre de variable / ; \n");
                                                            $$ = ans;   
                                                       }
        | tipoDouble   varNoDecla                ';'    {   
                                                            insert(tablaSim, "double", $2,  "0");
                                                            sprintf(ans,"Tipo de declaracion: tipo double / nombre de variable / ; \n");
                                                            $$ = ans;   
                                                       }
        | tipoString   varNoDecla                ';'    {    
                                                            insert(tablaSim, "string", $2,  "");
                                                            sprintf(ans,"Tipo de declaracion: tipo string / nombre de variable / ;\n");
                                                            $$ = ans;
                                                       }
;
//Reglas de produccion para la asignacion de variables, solo para variables que ya existen (por ello solo son los token de var existente)
asignacion:  stringDeclarado  '=' expString   ';'            { update(tablaSim, $1,  $3);                        }
            | intDeclarado '=' expInt  ';'                   { sprintf(ans, "%d", $3);update(tablaSim, $1, ans); }
            | doubleDeclarado  '=' expDouble   ';'           { sprintf(ans, "%f", $3);update(tablaSim, $1, ans); }
;   
//Si un valor en la TS ya existe o no pero no se puede almacenar el tipo de dato en la variable porque esta ultima es de otro tipo.
errorAsignaTip: stringDeclarado  '=' expInt ';'             {  } //Si una variable en TS ya existe, no se puede hacer del tipo int,double
                | stringDeclarado  '=' expDouble  ';'             {  }
                | intDeclarado '=' expString  ';'                 {  } 
                | intDeclarado '=' expDouble  ';'                 {  }
                | doubleDeclarado  '=' expString  ';'             {  }
                | doubleDeclarado  '=' expInt ';'                 {  }
                | tipoString  varNoDecla '=' expInt ';'         {  } //Si una variable no existe en TS, no se puede asignar string a int
                | tipoString  varNoDecla '=' expDouble  ';'     {  }
                | tipoInt varNoDecla '=' expString  ';'         {  }
                | tipoInt varNoDecla '=' expDouble  ';'         {  }
                | tipoDouble  varNoDecla '=' expInt ';'         {  }
                | tipoDouble  varNoDecla '=' expString  ';'     {  }
;
//Reglas de produccion para errores de tipo, operaciones no permitidas.
errorOpTipo:  expString  '+' expInt  ';'               {  } //Errores de tipo con string left -> int right
          | expString  '-' expInt  ';'               {  }
          | expString  '*' expInt  ';'               {  }
          | expString  '/' expInt  ';'               {  }
          | expString  '%' expInt  ';'               {  }
          | expString  '^' expInt  ';'               {  }
          | expString  '+' expDouble  ';'                {  }//Errores de tipo con string left -> double right
          | expString  '-' expDouble  ';'                {  }
          | expString  '*' expDouble  ';'                {  }
          | expString  '/' expDouble  ';'                {  }
          | expString  '%' expDouble  ';'                {  }
          | expString  '^' expDouble  ';'                {  }
          | expInt '+' expString  ';'                {  } //Errores de tipo con int left -> string right
          | expInt '-' expString  ';'                {  }
          | expInt '*' expString  ';'                {  }
          | expInt '/' expString  ';'                {  }
          | expInt '%' expString  ';'                {  }
          | expInt '^' expString  ';'                {  }
          | expDouble  '+' expString  ';'                {  }//Errores de tipo con double left -> string right
          | expDouble  '-' expString  ';'                {  }
          | expDouble  '*' expString  ';'                {  }
          | expDouble  '/' expString  ';'                {  }
          | expDouble  '%' expString  ';'                {  }
          | expDouble  '^' expString  ';'                {  }
          | '-' expString                            {  }//Intentar definir una cadena negativa
          | expString  '*' expString                     {  }//Operaciones no permitidas con cadenas
          | expString  '/' expString                     {  }
          | expString  '%' expString                     {  }
          | expString  '^' expString                     {  }
;
//No se puede utilizar una variable que no haya sido previamente definida (combinaciones de varNoDecla OPERADOR expresion)
errorVarDefinida: varNoDecla                                         {  } //Variable inexistente en TS
                   | expInt '+' errorVarDefinida                     {  }//expresion entera y varNoDecla
                   | expInt '-' errorVarDefinida                     {  }
                   | expInt '*' errorVarDefinida                     {  }
                   | expInt '/' errorVarDefinida                     {  }
                   | expInt '%' errorVarDefinida                     {  }
                   | expInt '^' errorVarDefinida                     {  }
                   
                   | errorVarDefinida '+' expInt                     {  } 
                   | errorVarDefinida '-' expInt                     {  }
                   | errorVarDefinida '*' expInt                     {  }
                   | errorVarDefinida '/' expInt                     {  }
                   | errorVarDefinida '%' expInt                     {  }
                   | errorVarDefinida '^' expInt                     {  }
                   
                   | expDouble '+' errorVarDefinida                      {  } 
                   | expDouble '-' errorVarDefinida                      {  }
                   | expDouble '*' errorVarDefinida                      {  }
                   | expDouble '/' errorVarDefinida                      {  }
                   | expDouble '^' errorVarDefinida                      {  }
                   
                   | errorVarDefinida '+' expDouble                      {  }
                   | errorVarDefinida '-' expDouble                      {  }
                   | errorVarDefinida '*' expDouble                      {  }
                   | errorVarDefinida '/' expDouble                      {  }
                   | errorVarDefinida '^' expDouble                      {  }
                   
                   | expString '+' errorVarDefinida                      {  }
                   | expString '-' errorVarDefinida                      {  }
                   | expString '*' errorVarDefinida                      {  }
                   | expString '/' errorVarDefinida                      {  }
                   | expString '%' errorVarDefinida                      {  }
                   | expString '^' errorVarDefinida                      {  }
                   
                   | errorVarDefinida '+' expString                      {  }
                   | errorVarDefinida '-' expString                      {  }
                   | errorVarDefinida '*' expString                      {  }
                   | errorVarDefinida '/' expString                      {  }
                   | errorVarDefinida '%' expString                      {  }
                   | errorVarDefinida '^' expString                      {  }
                   
                   | errorVarDefinida '+' errorVarDefinida                         {  }
                   | errorVarDefinida '-' errorVarDefinida                         {  }
                   | errorVarDefinida '*' errorVarDefinida                         {  }
                   | errorVarDefinida '/' errorVarDefinida                         {  }
                   | errorVarDefinida '%' errorVarDefinida                         {  }
                   | errorVarDefinida '^' errorVarDefinida                         {  }
                   
                   | '-' errorVarDefinida                                {  } //Intentar restar una variable no definida
                   | '('    errorVarDefinida      ')'                    {  } //Obtener el valor de una variable no definida
                   
                   | varNoDecla '=' expInt ';'                            {  } //Intentar asignar algo a una variable no definida
                   | varNoDecla '=' expDouble  ';'                        {  }
                   | varNoDecla '=' expString  ';'                        {  }
                   
                   | intDeclarado '=' errorVarDefinida ';'                         {  } //Intentar asignar una variable no definida a una sí definida
                   | doubleDeclarado  '=' errorVarDefinida ';'                     {  }
                   | stringDeclarado  '=' errorVarDefinida ';'                     {  }
                   | varNoDecla '=' errorVarDefinida ';'                     {  } //Intentar asignar una variable no definida a otra no definida  
; 
//Reglas de produccion usadas con variables ya existentes
errorRedifincion: tipoString stringDeclarado ';'     {  }//No se permite volver a definir variables del mismo tipo
                   | tipoDouble doubleDeclarado ';'  {  }
                   | tipoInt intDeclarado ';'        {  }

                   | tipoString doubleDeclarado ';'  {  } //No se permite volver a definir variables con otro tipo de datos
                   | tipoString intDeclarado ';'     {  }
                   | tipoDouble stringDeclarado ';'  {  }
                   | tipoDouble intDeclarado ';'     {  }
                   | tipoInt stringDeclarado ';'     {  }
                   | tipoInt doubleDeclarado ';'     {  }
                   
                   | tipoString stringDeclarado  '=' expInt  ';'       {  }//No se permite volver a declarar variables y asignar con variables del mismo tipo
                   | tipoString intDeclarado  '=' expInt ';'           {  }
                   | tipoString doubleDeclarado  '=' expDouble ';'     {  }

                   | tipoString stringDeclarado  '=' expDouble   ';'     {  }//No se permite volver a declarar variables y asignar con variables de diferentes tipos
                   | tipoString stringDeclarado  '=' expString   ';'     {  }
                   | tipoString intDeclarado  '=' expDouble  ';'         {  }
                   | tipoString intDeclarado  '=' expString  ';'         {  } 
                   | tipoString doubleDeclarado  '=' expInt  ';'         {  }
                   | tipoString doubleDeclarado  '=' expString   ';'     {  }

                   | tipoString stringDeclarado  '=' errorVarDefinida ';'     {  } //No se permite volver a declarar variables y asignar con variables desconocidas
                   | tipoString doubleDeclarado  '=' errorVarDefinida ';'     {  }
                   | tipoString intDeclarado  '=' errorVarDefinida ';'        {  }
;

%%

int yyerror(char * s) {
  printf("YYERROR: %s \n", s);
}

int main() {
  tablaSim = (lista*) malloc(sizeof(lista));
  yyparse();
}

