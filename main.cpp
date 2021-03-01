#include "control.h"
#include "food.h"
#include "snake.h"
#include "unit.h"
#include <iostream>
#include <mysql.h>
#define user "root"
#define pwd "123456"
#define host "localhost"
#define database "tanchishe"
//#pragma comment(lib,"libmysql.lib")
//void mysql_insert();
using namespace std;
MYSQL* mysql;
MYSQL_RES* results;
MYSQL_ROW sql_row;
unsigned int port = 3306;
int main()
{
	Gameset* set = new Gameset;
	set->run();
	//mysql_insert();
}

//void mysql_insert()
//{
//	int result;
//	/*int score = set->score;*/
//	int score = 30;
//	mysql_init(mysql);
//	if (!mysql_real_connect(mysql, host, user, pwd, database, port, NULL, 0))
//	{
//		mysql_query(mysql, "charset=GBK");
//		result = mysql_query(mysql, "insert into ranking_list valuse(1,'qisong_Cao',30)");
//	}
//}
