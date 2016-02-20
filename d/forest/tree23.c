//Cracked by Roath
// Jay 7/9/96

#include "tree.h"
 
void create()
{
    int i;
        set("short", "树上");
        set("long", @LONG
树上枝密叶茂，树干上长满青苔。树叶上爬着些有毒的昆虫，在阳
光照不到的地方蠕动。林间各种各样的鸟儿在欢快地啼鸣。一些生活在
树上的动物上蹿下跳忽左忽右地在林子里活动。
LONG
        );

/*	set("objects", ([
		__DIR__"npc/mulang" : 1,
	]));
*/

	set("climbup",__DIR__"tree33");
	set("climbright",__DIR__"tree22");
	set("climbleft",__DIR__"tree24");

	set("cost", 3);
        setup();
}

