Action()
{

	int randomNum;

	randomNum=rand()%3+1;

	web_set_max_html_param_len("50000");


	web_reg_save_param_ex(
						"ParamName=shop_id",
						"LB=\"shop_id\":\"",
						"RB=\",\"watermark\":true",
						SEARCH_FILTERS,
						LAST);

	web_custom_request("owner",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=owner&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_reg_save_param_ex("ParamName=tag_Id",
						  "LB=tagId\":",
						  "RB=,\"count",
						  "Ordinal=all",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_transaction("�������ҳ");


	web_custom_request("get_tags_except",
					   "URL={requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id}&token={userToken}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_save_string(lr_paramarr_random("tag_Id"), "tag_Id_random"); 

/*
��Ϣ����
	lr_message("lr_message��Ϣ����:%s",lr_eval_string("{tag_Id_random}"));
	lr_output_message("output��Ϣ:%s",lr_eval_string("{tag_Id_random}"));
	lr_error_message("error��Ϣ:%s",lr_eval_string("{tag_Id_random}"));
	//ǰ3������־���ؿ���
	lr_log_message("log��־��Ϣ:%s",lr_eval_string("{tag_Id_random}"));
	lr_debug_message(LR_MSG_CLASS_BRIEF_LOG, "debug������Ϣ:%s",lr_eval_string("{tag_Id_random}"));
*/

/*	
���㣺
	web_reg_find("Fail=NotFound",
			"Search=Body",
			"SaveCount=success",
			"Text={tag_Id_random}",
			LAST);
*/
	lr_think_time(3);

	lr_start_sub_transaction("��ǩ����ҳ","�������ҳ");

	lr_message("lr_message��Ϣ����:%s",lr_eval_string("{tag_Id_count}"));
	lr_save_int(randomNum, "randomNum");
//	lr_message("lr_message��Ϣsave���ͺ���:%d",randomNum);

    
	if(atoi(lr_eval_string("{tag_Id_count}")) > 0){

//	if(strcmp(lr_eval_string("{tag_Id_count}"),lr_eval_string("{randomNum}")) ==0 ){

//	lr_message("lr_message�ɹ���Ϣ:%s",lr_eval_string("{randomNum}"));

	web_custom_request("tag_list",
					   "URL={requestUrl}/service/album/get_album_themes_list.jsp?act=tag_list&shop_id={shop_id}&tag_id=[{tag_Id_random}]&group_id=&search_value=&search_img=&start_date=&end_date=&from_id=",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

		lr_end_sub_transaction("��ǩ����ҳ",LR_PASS);

	}else{

//		lr_message("lr_messageʧ����Ϣ:%s",lr_eval_string("{randomNum}"));

		lr_end_sub_transaction("��ǩ����ҳ",LR_FAIL);

//		lr_output_message("���û��̵������᣺%s���ޱ�ǩ",lr_eval_string("{shop_id}"));
	}

	lr_end_transaction("�������ҳ",LR_AUTO);


	return 0;
}
