//Cracked by Roath
// room: /mingjiao/yinshandao.c

inherit ROOM;

void create()
{
        set("short", "银山道");
        set("long", @LONG
这里是汉代人为修建的一条山道，据说此道修成后，每逢月朗星稀之
夜，整条道便闪出银色光泽，故而得名。年深日久，此道破损了不少，不
过仍然平坦易行。
LONG );

        set("exits", ([
                "south" : __DIR__"tushantai",
                "northup" : __DIR__"hanku",
                "westup" : __DIR__"jicongling",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}