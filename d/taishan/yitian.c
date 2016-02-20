//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "一天门");
	set("long", @LONG
从岱宗坊上山大约走四里，便来到一天门。北面有一座天阶坊，过了此坊便
进入了登泰山的盘道。南面有一座更衣亭，士大夫们及其随从，都会在这里换上
轻便的服装，才继续登山。从一天门向北眺望，南天门与十八盘在云雾明灭间或
隐或现，登泰山的人到此已有观止之叹。附近有一牌坊，上写「孔子登临处」，
相传为「孔子过泰山侧」的故事发生的地方。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"doumo",
		"southdown" : __DIR__"baihe",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

