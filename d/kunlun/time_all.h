//Cracked by Roath
//maked By wzf 98 11 30
#include <localtime.h>
#include <ansi.h>
int get_month()
{
	return (localtime(time()*60)[LT_MON] + 1);
}
int get_hour()
{
	return (localtime(time()*60)[LT_HOUR] + 1)%24/2;
}
int get_day()
{
	int hour;
	hour=get_hour();
	if(hour>2&&hour<9)
	 return 1;
	 return 0;
}
int get_season()
{
	int season;
	season=get_month();
	 switch( season ) 
	 {
	  case 1:
		  return 1;
		  break;
	  case 2:
		  return 1;
		  break;
	  case 3:
		  return 1;
		  break;
	  case 4:
		  return 2;
		  break;
	  case 5:
		  return 2;
		  break;
	  case 6:
		  return 2;
		  break;
	  case 7:
		  return 3;
		  break;
	  case 8:
		  return 3;
		  break;
	  case 9:
		  return 3;
		  break;
	  case 10:
		  return 4;
		  break;
	  case 11:
		  return 4;
		  break;
	  case 12:
		  return 4;
		  break;
	 }
}



