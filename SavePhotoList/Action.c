Action()
{

	web_set_max_html_param_len("10240");

//�����ע�б�-->�����ϼ����-->��������-->��ȡ��ǩ����-->������Ʒ-->��������б�

	lr_start_transaction("�ϼ���������Ʒ");

	web_reg_save_param_ex("ParamName=shop_id",
						  "LB=shop_id\":\"",
						  "RB=\",\"total_goods",
						  "NotFound=warning",
						  "Ordinal=All",
						  SEARCH_FILTERS,
						  LAST);

	lr_start_sub_transaction("��������б�","�ϼ���������Ʒ");

	web_custom_request("attention",
					   "Url=https://{requestUrl}/service/album/get_album_list.jsp?act=attention&search_value=&page_index=1&client_type=ios&token={userToken}&version=2109",
					   "Method=POST",
					   "Mode=HTTP",
					    LAST);

	lr_end_sub_transaction("��������б�",LR_AUTO);

	lr_start_sub_transaction("�����ϼ����","�ϼ���������Ʒ");

	web_reg_save_param_ex("ParamName=goods_id",
						  "LB=goods_id\":\"",
						  "RB=\",\"miniapp_name",
						  "NotFound=warning",
						  "Ordinal=All",
						  SEARCH_FILTERS,
						  LAST);

	web_reg_save_param_ex("ParamName=imges",
							"LB=\"imgsSrc\":",
							"RB=,\"old_time\"",
							"NotFound=warning",
						    "Ordinal=All",
							SEARCH_FILTERS,
							LAST);

	web_custom_request("single_album",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id_2}&search_value=&search_img=&start_date=&end_date=&tag=[]&page_index=1&from_id=&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
                       LAST);

	web_custom_request("get_tags_except",
					   "Url=https://{requestUrl}/service/album/album_theme_tag_operation.jsp?act=get_tags_except&has_video=0&shop_id={shop_id_2}&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
                       LAST);

	lr_end_sub_transaction("�����ϼ����",LR_AUTO);


    lr_save_string(lr_paramarr_random("goods_id"), "goods_id_random");

	lr_save_string(lr_paramarr_random("imges"), "imges_random");


//	lr_output_message(lr_eval_string("{goods_id_random}"));
	lr_start_sub_transaction("��������","�ϼ���������Ʒ");

	web_custom_request("hold_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=hold_theme&client_type=ios&token={userToken}&version=2302&shop_id={shop_id_2}&goods_id={goods_id_random}",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	web_custom_request("get_watermark",
					   "Url=https://{requestUrl}/service/album/album_mark_operation.jsp?act=get_watermark&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	web_custom_request("get_all_tag",
					   "Url=https://{requestUrl}/service/album/album_group.jsp?act=get_all_tag&type=0&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	web_reg_save_param_ex("ParamName=mark_code",
						  "LB=mark_code\":\"",
						  "RB=\"},\"errmsg",
						  "NotFound=warning",
						  "Ordinal=All",
						  SEARCH_FILTERS,
						  LAST);

	lr_end_sub_transaction("��������",LR_AUTO);

    web_convert_param("imges_random", "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST );

	web_custom_request("get_markcode",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=get_markcode&client_type=ios&goods_id={goods_id_random}&platform=app&shop_id={shop_id_2}&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	lr_start_sub_transaction("�����ϼ���Ʒ","�ϼ���������Ʒ");

	web_custom_request("save_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=save_theme&album_id={shop_id_2}&client_type=ios&item_id={goods_id_random}&main_imgs={imges_random}&mark_code={mark_code_1}&personal=0&platform=app&share_type=-1&source_type=100&source_url=&sub_imgs=&title=Testing_{randomNum}&token={userToken}&version=2302",
					   "Method=POST",
					   "Mode=HTTP",
					    LAST);

	lr_end_sub_transaction("�����ϼ���Ʒ",LR_AUTO);

	lr_start_sub_transaction("�������","�ϼ���������Ʒ");

	web_custom_request("single_album",
					   "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=single_album&shop_id={shop_id_2}&search_value=&search_img=&start_date=&end_date=&tag=[]&page_index=1&from_id=&slip_type=0&client_type=ios&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);

	lr_end_sub_transaction("�������",LR_AUTO);
	

	web_custom_request("qiuniu",
					   "Url=https://{requestUrl}/service/get_qiuniu_token.jsp",
					   "Method=GET",
					   "Mode=HTTP",
						LAST);


	lr_end_transaction("�ϼ���������Ʒ",LR_PASS);

	return 0;
}
