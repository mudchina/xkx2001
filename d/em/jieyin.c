//Cracked by Roath
// /d/emei/jieyin.c 接引殿
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "接引殿");
	set("long", @LONG
接引殿右边濒崖，是金钢嘴。崖下有一块巨石，形状似钟，故名「钟石」。
对面有一石，高耸十余丈，叫「仙人石」。由此向上仰攀即到万行庵，北下经
「八十四盘」至洗象池。
LONG
	);
	set("exits", ([
		"westup" : __DIR__"wanxing",
		"northwest" : __DIR__"pan82",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}
