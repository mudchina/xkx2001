//Cracked by Roath
// Room: /d/beijing/chongwenjie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "north"  : __DIR__"chongwenmen",
	  "west"  : __DIR__"zhengyangdajie",
	  "northeast": __DIR__"tianshuijing",
	]));
    }else{
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"zuoanmen",
	  "north"  : __DIR__"chongwenmen",
	  "northeast": __DIR__"tianshuijing",
	  "west"  : __DIR__"zhengyangdajie",
	  "east"  : __DIR__"guangqumen",
	]));
    }
}

void create()
{
	set("short", "崇文门大街");
	set("long", @LONG
这里是热闹的崇文门大街。街上多是来往的商人，有时也能看见马车载着达官
要员经过。
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
