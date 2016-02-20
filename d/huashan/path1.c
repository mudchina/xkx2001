//Cracked by Roath
// path1.c

inherit ROOM;

void create()
{
        set("short", "华山脚下");
	set("long", @LONG
这里是华山脚下，南面就是素有「奇峰天下第一山」的西岳华山，华
山由于远望宛如一朵白莲花，因而得名（古时，「华」与「花」通）。西
面有个小村庄，北边有几间房屋。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hsstreet4",
  "north" : __DIR__"yuquan",
  "southeast" : __DIR__"shaluo",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
