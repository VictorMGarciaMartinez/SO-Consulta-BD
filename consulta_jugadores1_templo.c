//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char mapa[60];
	strcpy(mapa, "'templo'");
	char consulta [200];
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "bdFireWater",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
		
		// Ahora vamos a realizar la consulta
		printf ("Ahora encontraremos el username de los usuarios que han jugado en el mapa 'templo' como jugador 1: \n");
		// construimos la consulta SQL
		strcpy (consulta,"SELECT jugador.username FROM (jugador, partida, historial) WHERE partida.mapa = "); 
		strcat (consulta, mapa);
		strcat (consulta," AND historial.id_p = partida.id AND historial.id_j = jugador.id AND historial.posicion = 1;");
		// hacemos la consulta 
		err=mysql_query (conn, consulta); 
		if (err!=0) {
			printf ("Error al consultar datos de la base %u %s\n",
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
		//recogemos el resultado de la consulta 
		resultado = mysql_store_result (conn); 
		row = mysql_fetch_row (resultado);
		if (row == NULL)
			printf ("No se han obtenido datos en la consulta\n");
		else
			while (row != NULL){
				printf("Username: %s\n", row[0]);
				// obtenemos la siguiente fila
				row = mysql_fetch_row (resultado);
			}
		// cerrar la conexion con el servidor MYSQL 
		mysql_close (conn);
		exit(0);
}