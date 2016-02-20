//Cracked by Roath
void unconcious()
{
       object ob = this_object();
       object cake;

        message_vision("\n突然，只见$N掏出一张烧饼吞进肚里！\n",
                ob);
       if (cake = present("shaobing",ob)) destruct(cake);
//     ob->die();
       ob->disable_player(" <昏迷不醒>");
        ob->set("jing", 0);
        ob->set("qi", 0);
        COMBAT_D->announce(ob, "unconcious");

        call_out("revive", random(100 - query("con")) + 30);

}

