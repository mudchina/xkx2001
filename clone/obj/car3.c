//Cracked by Roath
// car3.c
// by aln 4 / 98

inherit ROOM;
inherit F_CLEAN_UP;
inherit F_UNIQUE;

void reset()
{}

void create()
{
        set("short", "³µ¿â");
        set("no_clean_up", 1);

        setup();
}
