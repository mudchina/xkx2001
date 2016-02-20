//Cracked by Roath
// /d/mingjiao/fuw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "蝠王殿");
	set("long", @LONG
此间乃明教蝠王殿。堂上甚是空旷。两旁置有兵器架，上摆十八种武
器。正对殿门的壁墙上绘着一保青色大蝙蝠，双翼大张，狰狞可怖，口边
还缀着几滴红色血色点，令人不寒而栗。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"daguangchang",
]));
	set("objects",([
//                CLASS_D("mingjiao")+"/weiyixiao" : 1,
	]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
