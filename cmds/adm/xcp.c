// xcp.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// 为了避免递归太深，请不要设置进入级别超过16级. JackyBoy
// Tips:为了不影响可以连续发命令，X系列命令可以将递归进行call_out调用！
//      但这只是想法我自己并未去实现它!

inherit F_CLEAN_UP;
int help();
int do_cp(string,string,string,int);
string resolvePath(string,int);
int main(object me, string arg)
{
	string  path,wild,dest;
	int level;
	level=15;
	seteuid(geteuid(me));
	write("X c 命令 v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"主页：http://mud.yn.cninfo.net/jackyboy\n邮件：jackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,dest)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,dest)!=3)
    		if(sscanf(arg,"%s %s",path,dest)!=2)
    		{
    			write ("\n参数解析错误。\n\n");
    			return help();
    		}
    }
    else
    	level=15;//带-d参数默认级别为所有级
    if(level<0) level=1;
    if(level>15) level=15;
    dest=resolve_path(me->query("cwd"),dest);
    //处理path分解出wild
    path=resolve_path(me->query("cwd"),path);
    write("未解析路径：\t"+path+"\n");
    //write("欲复制的目的路径：\t"+dest+"\n");
    write("搜索目录级别：\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("解析后路径：\t"+path+"\n");
    write("解析后通配符：\t"+wild+"\n");
    write("解析后目标路径：\t"+dest+"\n\n");
    do_cp(path,wild,dest,level);
    write("\n复制结束。\n");
    return 1;
}

string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//对这个情况特殊处理
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op为非0表示需要返回路径
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//上面的程序不好，不能对同名路径正确处理，比如不能在/log/log文件里搜索
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("合并"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
int do_cp(string path,string wild,string dest,int level)
{
	//int i;string *fs;
	string file;
	reset_eval_cost();//重新设置剩余执行时间，必须设置！
	if(dest[sizeof(dest)-1]!='/')//这句必不可少，不然就不能正确生成目标路径
    	dest=dest+"/";
	if(this_player()->query("env/debug"))
		write("开始复制"+path+wild+"到"+dest+"\n");
	if(level<0)
	{
		//write("级别限制，不能再进入。\n");
		return 0;
	}
	
	foreach(file in get_dir(path+wild))
	{

		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//无法读取该目录，跳过
				break;
			case -2:
				if(file!="."&&file!="..")
					do_cp(path+file+"/","*",dest+file+"/",level-1);
				break;
			default:
				assure_file(dest+file);
				//write("复制文件："+path+file+"到"+dest+file+"\n");
				cp(path+file,dest+file);
		}
		
	}
	return 1;
}

int help()
{
  write(@HELP

X cp 命令 v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/2
主页：http://mud.yn.cninfo.net/jackyboy
邮件：jackyboy@126.com


指令格式 : xcp [-d[0-15]] 源路径或文件 目标路径
此指令可让你把指定的目录或文件复制到指定的目录去。
支持通配符，可以指定复制一定的目录深度。
HELP
    );
    return 1;
}
