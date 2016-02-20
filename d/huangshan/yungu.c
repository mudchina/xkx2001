//Cracked by Roath
// 云谷
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "云谷");
    set("long", @LONG
这是钵孟峰和罗汉峰之间的一条峡谷。站在谷地中央，环顾四周，
面面受奇。远可欣赏云回雾绕的巍巍群峰，近可领略迸珠溅玉的碧
溪清泉。谷中有一古刹。相传南北朝时，有一僧人云游到这里，再
也不想离开；就在这修禅礼佛，给他的禅堂取名新罗庵。後有个文
人来此游览，狂喜之余挥笔题了“云谷”二字，刻在门头，作为匾
额。故得名“云谷寺”。寺前有两株千年古树，南面一株是铁杉，
北面一株是黄杉。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southwest" : __DIR__"shanlu1",
	"southeast" : __DIR__"jiulong",
	"northup" : __DIR__"xianren",
	
		 ])
	 );
    setup();
    replace_program(ROOM);
}
