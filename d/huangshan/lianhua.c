//Cracked by Roath
// 莲花峰
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "莲花峰");
    set("long", @LONG
置身峰顶，颇有“顶天立地”之感，遥望四方，千峰竞秀，万壑
争流，美不胜收。从这里可东望天目，西瞻匡庐，北窥九华和长江。
雨後更可纵观四面八方的云海，无比壮观。往北过了两块大石(stone)
就到了百步云梯。
LONG);
    set("item_desc", 
    	([
      	"stone" : 
		"两块大石一块象千年老龟，另一块形如卧睡的长蛇。\n"
   	])
	);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"yanwang",
	"north" : __DIR__"baibu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
