//Cracked by Roath
// 小心坡
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "小心坡");
    set("long", @LONG
小心坡一面临绝壁，一面临深渊，你踏上石蹬，禁不住要两腿发
软。一阵大风吹过，坡前两山夹峙成峡，风头被阻，激荡回旋。你一
不小心，几乎被风卷坠绝壁。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"yixian1",
	"southeast" : __DIR__"banshan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
