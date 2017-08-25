/*
 ============================================================================
 Name        : SampleCPP.c
 Author      : Rafael Rocha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <my_global.h>
#include <mysql.h>

int main() {

	//listFromDatabase();
	soma();

	return 0;
}

void soma() {

	int num1, soma, numX;
	char resp;

	printf("Entre com o primeiro número: ");
	scanf("%i/n", &num1);

	soma = num1;

	do {

		printf("Entre com o proximo número: ");
		scanf("%i/n", &numX);

		soma = soma + numX;

		printf("Deseja continuar ? (S/N): ");
		scanf(" %c", &resp);

	} while (resp == 'S');

	printf("O resultado da soma é %i", soma);
}

void insertDatabase() {

	char sql;
	char name = "Totó";
	char owner = "Didi Mocó";
	char species = 'catioro';
	char gender = "M";
	sql = "insert into pet values ('" + name + "','" + owner + "','" + species + "','" + gender + "');";

	MYSQL *connection;
	MYSQL_RES *resource;
	MYSQL_ROW result;

	char *hostAddress = "127.0.0.1";
	char *user = "root";
	char *password = "my-secret-pw";
	char *database = "teste";
	int port = 3307;

	printf("MySQL client version: %s\n", mysql_get_client_info());

	/* Intitialize connection to database, and MYSQL structure. */
	connection = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(connection, hostAddress, user, password, database,
			port,
			NULL, 0)) {
		printf("%s\n", mysql_error(connection));
	}

	/* SELECT more data from world database. */
	mysql_query(connection, sql);

	/* Closes connection to database, frees memory used by connection. */
	mysql_close(connection);

	/* Frees up other memory used by the libmysqlclient. */
	mysql_library_end();

}

void listFromDatabase() {

	MYSQL *connection;
	MYSQL_RES *resource;
	MYSQL_ROW result;

	char *hostAddress = "127.0.0.1";
	char *user = "root";
	char *password = "my-secret-pw";
	char *database = "teste";
	int port = 3307;

	printf("MySQL client version: %s\n", mysql_get_client_info());

	/* Intitialize connection to database, and MYSQL structure. */
	connection = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(connection, hostAddress, user, password, database,
			port,
			NULL, 0)) {
		printf("%s\n", mysql_error(connection));
	}

	/* SELECT more data from world database. */
	mysql_query(connection, "SELECT name, owner FROM pet ORDER BY name");

	/* Resource struct with rows of returned data. */
	resource = mysql_use_result(connection);

	/* Print out all our cities with populations */
	while ((result = mysql_fetch_row(resource))) {
		printf("%s | %s\n", result[0], result[1]);
	}

	/* Free memory used by resource */
	mysql_free_result(resource);

	/* Closes connection to database, frees memory used by connection. */
	mysql_close(connection);

	/* Frees up other memory used by the libmysqlclient. */
	mysql_library_end();

}
