//Cracked by Roath
// hsstreet1
// qfy Oct 15, 97

inherit ROOM;

void create()
{
        set("short", "村外土路");
        set("long", @LONG
村外的土路向前延伸，路上有些稀稀疏疏的足印，悠闲的村民挑着扁担或赶着
牲畜缓缓走过。路边草丛渐密，低矮的灌木杂乱无章地排列着。巍峨的西岳华山遥
遥在望。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
                "west" : "d/village/eexit",
                "east" : __DIR__"hsstreet2",
        ]));
        
        set("objects", ([ 
                "/d/village/npc/dog": 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
