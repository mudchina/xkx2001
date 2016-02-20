//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "中和殿");
	set("long",  @LONG
这里又称华盖殿，中极殿，是正方形殿。皇帝在太和殿举办大典
前，一般在此准备。另外，每十年一次的进呈玉碟（皇帝的家谱）仪
式也在此进行。


这是一个小宫殿，有一张极舒适的大床和一张宽大的软椅。每当
皇帝上朝累的时后，他就回到这里休息一会儿。在床上散放着几本古
书，好象是皇帝消磨时间用的。
LONG
	);

	set("exits", ([
		"north" : __DIR__"baohedian",
		"south" : __DIR__"taihedian",
        "west"  : __DIR__"xiaodao1",
        "east"  : __DIR__"xiaodao2",
	]));

	setup();
	replace_program(ROOM);
}
