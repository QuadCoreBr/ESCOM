digito [0-9]
entero ([-]|[+])?{digito}+
decimal ([-]|[+])?{digito}*\.{digito}+
palabraReserv ([iI][nN][tT])|[cC][hH][aA][rR]|[wW][hH][iI][lL][eE]|[fF][oO][rR]|[dD][oO][uU][bB][lL][eE]|[eE][lL][sS][eE]|[lL][oO][nN][gG]|[sS][wW][iI][tT][cC][hH]|[cC][aA][sS][eE]|[eE][nN][uU][mM]|[rR][eE][tT][uU][rR][nN]|[fF][lL][oO][aA][tT]|[vV][oO][iI][dD]|[gG][oO][tT][oO]|[dD][oO]|[iI][fF]
nombreVariable [_a-zA-Z]+[0-9]*[_a-zA-Z]*[0-9]*
opcionesNumeros {entero}|{decimal}
suma ({opcionesNumeros}\+)+{opcionesNumeros} 
resta ({opcionesNumeros}\-)+{opcionesNumeros} 	
multiplicacion ({opcionesNumeros}\*)+{opcionesNumeros}
division ({opcionesNumeros}\/)+{opcionesNumeros}	
opcionesAsignacion {nombreVariable}|{opcionesNumeros}
asignacion	{nombreVariable}\={opcionesAsignacion}
modulo [mM][oO][dD]\({opcionesNumeros}\)
potencia [pP][oO][wW]\({opcionesNumeros}\,{opcionesNumeros}\)
%%
{palabraReserv} {
		printf("Palabra Reservada");
        }
{nombreVariable}   {
		printf("Nombre de variable");
        }
{suma}  {
		printf("Suma");
		}
{resta} {
		printf("Resta");
		}
{multiplicacion} {
		printf("Multiplicacion");
		}
{division} {
		printf("Division");
		}
{asignacion} {
		printf("Asignacion");
		}
{modulo} {
		printf("Modulo");
		}
{potencia} {
		printf("Potencia");
		}
{entero} {
		printf("Numero entero");
		}		
{decimal} {
		printf("Numero decimal");
		}
%%
void main() {yylex();}