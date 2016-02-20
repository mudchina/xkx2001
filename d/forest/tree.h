//Cracked by Roath
// Jay 7/11/96

inherit ROOM;

int do_climb(string);

void init()
{
        add_action("do_climb","climb");
        add_action("do_climb","pa");
}

int do_climb(string arg)
{
    object me, here, ob;
    object *all;
    string destination;
    me = this_player();
    here = this_object();
    all = all_inventory(here);

    if (me->is_busy())
        return notify_fail("你现在正忙着呢！。\n");
    
    switch (arg) {
    case "up":
    case "shang":
        if ((string) destination = here->query("climbup")) {
          write("你向上爬去。\n");
          message("vision", me->name() + "爬到上面去了。\n",
                  environment(me),({me}));
          me->move(destination);

          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "从树下爬了上来。\n",
                  environment(me), ({me}));
        }  
        else write("这里不能向上爬。\n");
        break;
    case "down":
    case "xia":
        if ((string) destination = here->query("climbdown")) {
          write("你向下爬去。\n");
          message("vision", me->name() + "爬到下面去了。\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "从树上爬了下来。\n",
                  environment(me), ({me}));
        }
        else write("这里不能向下爬。\n");
        break;
    case "left":
    case "zuo":
        if ((string) destination = here->query("climbleft")) {
          write("你向左边爬去。\n");
          message("vision", me->name() + "攀着树枝荡到左面去了。\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/city/npc/maque");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/wudang/npc/monkey");
                ob->move(here);
          }

          message("vision", me->name() + "从右边荡了过来。\n",
                  environment(me), ({me}));
        }
        else write("这里不能向左爬。\n");
        break;
    case "right":
    case "you":
        if ((string) destination = here->query("climbright")) {
        write("你向右边爬去。\n");
          message("vision", me->name() + "攀着树枝荡到右面去了。\n",
                  environment(me),({me}));
          me->move(destination);
          if (random(5) == sizeof(all)) {
                ob = new("/d/wudang/npc/little_monkey");
                ob->move(here);
          }
          if (random(5) == sizeof(all)) {
                ob = new("/d/xingxiu/npc/snake");
                ob->move(here);
          }

          message("vision", me->name() + "从左边荡了过来。\n",
                  environment(me), ({me}));
        }
        else write("这里不能向右爬。\n");
        break;
    default:
        return 0;
    }
    return 1;
}
