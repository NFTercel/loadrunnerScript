Action()
{

//��ҳ������ͼƬ
	web_reg_save_param_ex(
	"ParamName=goods_id_list",
	"LB=goods_id\":\"",
	"RB=\",\"miniapp_name",
	"NotFound=warning",
    "Ordinal=All",
	SEARCH_FILTERS,
	LAST);	

	web_reg_save_param_ex(
	"ParamName=shop_id_list",
	"LB=shop_id\":\"",
	"RB=\",\"subimgsSrc",
	"NotFound=warning",
    "Ordinal=All",
	SEARCH_FILTERS,
	LAST);

	web_reg_save_param_ex(
	"ParamName=title",
	"LB=title\":\"",
	"RB=\",\"videoURL",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);

	web_reg_save_param_ex(
	"ParamName=imges",
	"LB=\"imgs\":",
	"RB=,\"watermark",
	"NotFound=warning",
	SEARCH_FILTERS,
	LAST);


	lr_start_transaction("����app��ҳ");

    web_custom_request("owner",
                       "Url=https://{requestUrl}/service/album/get_album_themes_list.jsp?act=owner&search_value=&search_img=&start_date=&end_date=&page_index=1&token={userToken}",
                       "Method=GET",
                       "Mode=HTTP",
                       LAST);

	lr_end_transaction("����app��ҳ",LR_PASS);

    lr_convert_string_encoding("{title}",LR_ENC_SYSTEM_LOCALE,LR_ENC_UTF8,"title");
    web_convert_param("imges", "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST ); 

	lr_start_transaction("������Ʒ");

	lr_start_sub_transaction("һ������","������Ʒ");

	web_custom_request("hold_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=hold_theme&client_type=ios&token={userToken}&version=2302&shop_id={shop_id_list_1}&goods_id={goods_id_list_1}",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);
	lr_end_sub_transaction("һ������",LR_AUTO);


	lr_start_sub_transaction("��ȡ��Ʒ����","������Ʒ");

	web_custom_request("get_markcode",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=get_markcode&client_type=ios&goods_id={goods_id_list_1}&platform=app&shop_id={shop_id_list_1}&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_custom_request("get_markcode",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp?act=get_markcode&client_type=ios&goods_id={goods_id_list_1}&platform=app&shop_id={shop_id_list_1}&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	web_custom_request("get_all_tag",
					   "Url=https://{requestUrl}/service/album/album_group.jsp?act=get_all_tag&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("��ȡ��Ʒ����",LR_AUTO);

	lr_start_sub_transaction("��ȡ�û��Ƿ�vip","������Ʒ");

	web_custom_request("get_vip_object",
					   "Url=https://{requestUrl}/service/account/user_info_operation.jsp?act=get_vip_object&client_type=ios&platform=app&token={userToken}&version=2302",
					   "Method=GET",
					   "Mode=HTTP",
					   LAST);

	lr_end_sub_transaction("��ȡ�û��Ƿ�vip",LR_AUTO);


	lr_start_sub_transaction("������Ʒ","������Ʒ");

	web_custom_request("save_theme",
					   "Url=https://{requestUrl}/service/album/album_theme_operation.jsp",
					   "Method=POST",
					   "Mode=HTTP",
					   "Body=act=save_theme&album_id={shop_id_list_1}&client_type=ios&item_id={goods_id_list_1}&main_imgs={imges}&mark_code=&personal=0&platform=app&share_type=2&source_type=100&source_url=&sub_imgs=&token={userToken}&version=2302&title={title}",
					   LAST);

	lr_end_sub_transaction("������Ʒ",LR_AUTO);


	lr_end_transaction("������Ʒ",LR_AUTO);

	return 0;
}
