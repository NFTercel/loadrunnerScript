Action()
{
   //��֤IP��ƭ����
	  char * ip ;
			ip = lr_get_vuser_ip();
		if (ip)
			lr_output_message("��ǰ�����û�ʹ�õ�IPΪ�� %s", ip);
		else
			lr_output_message("[enable IP spoofing ]ѡ��û�б����ã�");


       lr_start_transaction("�ٶ���ҳ");    //��������ʼ

       web_url("www.baidu.com", 
				"URL=http://www.baidu.com/", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				EXTRARES, 
				LAST);

       lr_end_transaction("�ٶ���ҳ",LR_AUTO);    //�����������

       return 0;
}
