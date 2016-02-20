//Cracked by Roath
// yunuci.c

inherit ROOM;

void create()
{
        set("short", "玉女祠");
	set("long", @LONG
玉女祠里供奉的到底是哪位玉女，有许多不同的说法，现在所能看到
的只一尊呆板的石像。祠中大石上有一处深陷，凹处积水清碧，这是玉女
的洗脸盆，碧水终年不干。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yunu",
]));
        set("resource/water", 1);
        set("no_clean_up", 0);

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
