//Cracked by Roath
// Room: /d/dali/feiwo.c  temp room for dali bandit

inherit ROOM;

void create()
{
	set("short", "匪窝");
	set("long", @LONG
土匪山贼强盗等聚集的匪窝。
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
