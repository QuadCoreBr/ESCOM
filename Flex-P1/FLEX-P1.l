digito [0-9]
entero ([-]|[+])?{digito}+
decimal ([-]|[+])?{digito}*\.{digito}+
palabraReserv int|char|while|for|double|else|long|switch|case|enum|return|float|void|goto|do|if
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
