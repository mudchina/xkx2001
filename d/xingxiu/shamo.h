//Cracked by Roath

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

       if (dir == "west")
          me->add_temp("mark/steps",1);
       if (dir == "east")
          me->add_temp("mark/steps",-1); 
	if (me->query("ridable"))
            me->delete_temp("mark/steps");
	if( !me->query("rided") && me->query("id") != "camel"){
            me->add("jingli", -50);
            me->add("water", -50);
        if(me->query("water") < 0)
            me->set("water", 0);
        }        

	ob = all_inventory(environment(me));
	if (me->query_temp("mark/steps") == 10)
         {
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/xingxiu/btshan");
	ob[i]->delete_temp("mark/steps");
        }
     	    me->set_temp("new_valid_dest", "/d/xingxiu/huyang1");
            me->delete_temp("mark/steps");
             tell_object(me, "你累得半死，终於走出了沙漠。\n");
	    return 1;
         }  

     if (me->query_temp("mark/steps") == -10)
	    {  
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/xingxiu/silk4");
	ob[i]->delete_temp("mark/steps");
        }
	       me->set_temp("new_valid_dest", "/d/xingxiu/silk4");
           me->delete_temp("mark/steps");
             tell_object(me, "你累得半死，终於走出了沙漠。\n");
	     return 1;
     	}
           
        return ::valid_leave(me, dir);
}
