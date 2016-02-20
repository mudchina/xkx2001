//Cracked by Roath
//ROOM: tulu.h

void create()
{
        set("short", "маб╥");
        set("long", TULU_DESC_LONG);
        
        set("outdoors", "beijing");
        set("exits", TULU_EXITS);
        set("cost", 10);

        setup();
        replace_program(ROOM);
}
