%{
        #include "PracticaFinal.tab.h"
        #include "TablaSimbolos.h"
        lista* tablaSim;
%}

digito [0-9]
entero {digito}+
decimal {digito}*\.{digito}+
identificador ([_a-zA-Z]+{digito}*)+
operadores [\+\-\*\%\^/] 
cadena \"([^\"])*\" 

%%
{entero}    {
                printf("\tNumero entero %s\n",yytext);
                yylval.Int = atoi(yytext);
                return (valorInt);
            }
{decimal}   {
                printf("\tNumero decimal %s\n",yytext);
                yylval.Double = atof(yytext);
                return (valorDouble);
            }
{operadores}    {
                        printf("\tOperador: %c\n",yytext[0]);
                        return (yytext[0]);
                }
"string"        {
                        printf("\tTipo string\n");
                        return (tipoString);
                }
"double"        {
                        printf("\tTipo double\n");
                        return (tipoDouble);
                }
"int"           {
                        printf("\tTipo int\n");
                        return (tipoInt);
                }
{identificador} {
                        nodo* ans = search(tablaSim, yytext);
                        yylval.String = strdup(yytext);
                        if (!ans) {
                        printf("\tVariable no declarada: %s\n", yytext);
                        return (varNoDecla);
                        }
                        else if (strcmp(ans->tipo, "integer") == 0) {
                        printf("\tVariable INT declarada: %s\n", yytext);
                        return (intDeclarado);
                        }
                        else if (strcmp(ans->tipo,  "double") == 0) {
                        printf("\tVariable DOUBLE declarada: %s\n", yytext);
                        return (doubleDeclarado);  
                        }
                        else if (strcmp(ans->tipo,  "string") == 0) {
                        printf("\tVariable STRING decladara: %s\n", yytext);
                        return (stringDeclarado);  
                        }
                }
{cadena}        {
                        printf("\tCadena sin comillas: %s \n",yytext);
                        char* aux = yytext; 
                        int i ;          
                        for(i=0; i < strlen(yytext); i++)
                        aux[i] = aux[i+1];
                        aux[i-2] = '\0';
                        yylval.String = aux;
                        
                        return (valorString);
                }
"\n"            {
                        printf("\tSalto de linea\n");
                        return (yytext[0]);
                }
"("             {
                        printf("\tParentesis abre\n");
                        return (yytext[0]);
                }
")"             {
                        printf("\tParentensis cierra\n");
                        return (yytext[0]);
                }
"="             {
                        printf("\tSimbolo igual\n");
                        return (yytext[0]);
                }
";"             {
                        printf("\tFin de expresion\n");
                        return (yytext[0]);
                }
.               ;
%%