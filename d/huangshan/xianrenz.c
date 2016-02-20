//Cracked by Roath
// 仙人指路
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "仙人指路");
    set("long", @LONG
走在山路上，只见两旁奇峰怪石，举目皆是；白云青松，争奇斗
幻。其中一块怪石，形如喜鹊，旁有青松可登，称为“喜鹊登梅”。
但当你来到一块巨石旁从侧面一望，“喜鹊”变成一位宽袖道袍的仙
人，举起右手，指点着路旁的一条蹊径。人们叫它“仙人指路”。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"xianren",
	"west" : __DIR__"yunfang",
	"northup" : __DIR__"mengbi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
