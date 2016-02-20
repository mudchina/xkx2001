//Cracked by Roath
// huli.c

inherit NPC;

void create()
{
        set_name("狐狸", ({ "fox" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只身体硕大的狗熊，它正瞪着眼睛看着你。\n");
        set("attitude", "peaceful");
        set("combat_exp", 10000);

        set("str", 40);
        set("dex", 60);

	set_temp("apply/attack", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/dexerity", 80);
        set_temp("apply/armor", 20);

        setup();
}

void init()
{
        ::init();

        if( interactive(this_player()) && living(this_object()) ) {
                remove_call_out("do_escape");
       	        call_out("do_escape", 3 + random(3));
        }
}

void die()
{
        object ob;

        message_vision("$N惨嚎一声，死了！\n", this_object());
        ob = new(DRUG_D("hulipi"));
        ob->move(environment());
        destruct(this_object());
}

void do_escape()
{
       if( is_busy() || !living(this_object()) ) {
               call_out("huli", 10 + random(10));
               return;
       }

       message_vision("狐狸看到有人过来了，“嗖——”的一下钻到了旁边的杂草中不见了！\n", this_object());
       destruct(this_object());
}
