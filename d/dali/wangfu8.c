//Cracked by Roath
// Room: /d/dali/wangfu8.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "书房");
	set("long","进入内堂，抬头迎面先看见一个赤金九龙青地大匾，上面写著斗大三个字，
是：「荣禧堂」；又有「万机宸翰」之宝。大紫檀雕螭案(desk)上设著三尺来高
青绿古鼎，悬著待漏随朝墨龙大画，一边是金锥彝，一边是玻璃盒，底下两溜十
六张紫檀交椅，又有一副对联，乃乌木联牌，镶著凿银的字迹，道：
　　　　　　　　　"HIW"座上珠玑昭日月，堂前黼黻焕烟霞。\n"NOR
);
	set ("item_desc", ([
		"desk" : "桌上摆放了好几本书，既有佛学经文，也有道家典籍，还有一本易经。\n"])) ;
	set("objects", ([
		"/kungfu/class/dali/zhengchun" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
