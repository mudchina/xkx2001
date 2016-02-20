//Cracked by Roath
// 苏堤
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "苏堤");
   set("long", @LONG
秋月之夜，月下观湖，满湖银波粼粼，阵阵微风，风中桂子飘香，
令人为之心醉。堤边泊着小舟是送游客去三潭映月的。往西边是去
花港，东面可见三潭映月遥立湖中，北边是锁澜桥，南面映波桥。
LONG        );

   set("exits", ([ /* sizeof() == 4 */ 
                  "south" : __DIR__"suti7", 
                  "north" : __DIR__"suti5", 
		  "west"  : __DIR__"huagang1",
                ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
