//Cracked by Roath
// room: /mingjiao/bailongdui.c

inherit ROOM;

void create()
{
        set("short", "白龙堆");
        set("long", @LONG
这是连接西，北两座高山的山梁。远望时，曲折如一条巨龙横卧。曾
有望气术士断言此地乃风水宝地，必出大富大贵之人，百余年来尚无应验。
常有迷信山民在此烧香，膜拜山神，也许真有奇异之处。
LONG );

        set("exits", ([
                "westup" : __DIR__"badake",
                "northup" : __DIR__"monan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}