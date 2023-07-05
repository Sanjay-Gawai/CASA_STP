Action()
{

	web_set_max_html_param_len("99999");
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");
	
	web_add_auto_header("x-app-environment", "");
	
	web_add_auto_header("x-app-platform", "ANDROID");

	web_add_auto_header("x-app-version", "0.9.13");

	web_add_header("authorization", "bearer {authToken}");
	
//	web_add_auto_header("maya-authorization", "bearer {authToken}");
	
	web_add_auto_header("Host", "stp-engage.maybank2u.com.my");
/*	
	web_url("init", 
		"URL=https://202.162.16.159/init?custKey=U2FsdGVkX1/rCOeMyY5ZaChqkE4Uv0sWAKcqp/FMxLot1A2oLT+GeqIrehc22aGLFNskzWY8giFbZ25Nvo1Jnw==", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("enrollment", 
		"URL=https://202.162.16.159/v2/enrollment", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"grantType\":\"PASSWORD\",\"tokenType\":\"PRELOGIN\",\"customerKey\":\"U2FsdGVkX1/rCOeMyY5ZaChqkE4Uv0sWAKcqp/FMxLot1A2oLT+GeqIrehc22aGLFNskzWY8giFbZ25Nvo1Jnw==\",\"mobileSDKData\":{\"deviceDetail\":\"Android\",\"deviceId\":\"k65v1_64_bsp\",\"deviceModel\":\"V2026\",\"deviceName\":\"V2026\",\"devicePrint\":\"string\",\"osType\":\"android\",\"osVersion\":\"30\",\"rsaKey\":\"6F6E230ED02D01488DD521FD5204400A\",\"hardwareID\":\"04e04f7b-7c86-47b7-829e-8ba45e7f9d5a\",\"screenSize\":\"720x1475\","
		"\"languages\":\"en\",\"multitaskingSupported\":true,\"timestamp\":\"\",\"geoLocationInfo\":{\"Latitude\":\"2.7291692\",\"Longitude\":\"102.0052373\",\"Status\":\"0\",\"Timestamp\":\"1687225268271\",\"HorizontalAccuracy\":\"12\"},\"emulator\":0,\"osId\":\"be681f3ff0c6e9db\",\"compromised\":0,\"sdkVersion\":\"4.4.0\",\"appState\":\"active\",\"keyChainErrorOnStoring\":\"NA\",\"keyChainErrorOnRetrieve\":\"NA\"},\"limitApproved\":false,\"marketing\":false}", 
		LAST);
*/

	web_reg_find("Text=\"message\":\"successful\"", LAST);

	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T01_USERDETAILS");
	
	web_url("userDetails", 
		"URL=https://202.162.16.159/v2/users/secure/userDetails", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T01_USERDETAILS",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T01_USERDETAILS", LR_AUTO);
	
	web_add_cookie("visid_incap_2853490=6jSdZSajR5Sxmg7p1YBdNGcEkWQAAAAAQUIPAAAAAABYummNzc6wNWAb2nbmzG6D; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("nlbi_2853490=PIu5QKX+fSdcP4SIeJDGsgAAAADpqvQEV/23ErGkFQ/Cm0xL; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("incap_ses_1136_2853490=ZLCABRkZDXhRvBFV9OLDD2cEkWQAAAAAfxvEgEa15KFAWrZK/YCVTg==; DOMAIN=stp-engage.maybank2u.com.my");

	web_reg_find("Text=\"message\":\"Success\"", LAST);
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T02_CHECKDOWNTIME");
	
	web_custom_request("checkDownTime", 
//		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/checkDownTime", 
		"URL=https://202.162.16.159/casa/openaccount/api/v1/checkDownTime", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=null", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T02_CHECKDOWNTIME",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T02_CHECKDOWNTIME", LR_AUTO);
	
	web_reg_find("Text=\"message\":\"Success\"", LAST);
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T03_MASTERDATA");
	
	web_custom_request("masterData", 
//		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/masterData", 
		"URL=https://202.162.16.159/casa/openaccount/api/v1/masterData", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T03_MASTERDATA",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T03_MASTERDATA", LR_AUTO);
	
	lr_think_time(tt);
	
//	web_add_auto_header("authorization", "bearer {authToken}");
	
//	web_add_auto_header("maya-authorization", "bearer {authToken}");
	
	web_js_run(
		"Code=encryptMyKey(LR.getParam('publickey'),LR.getParam('username')).toString();",
		"ResultParam=username_encrypted",
		SOURCES,
		"file=encryption.js",ENDITEM,
		LAST);
	
	web_reg_find("Text=\"code\":\"200\"", LAST);
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T04_VERIFYUSERNAME");
	
	web_custom_request("verifyUserName", 
		"URL=https://202.162.16.159/oauth/v1/verifyUserName", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
//		"Body={\"username\":\"EmpmyEa0t4J5kiqbxZjQJT7QK4X499JcbeHvb/LsrIrVyE6osXGP5GN2mwoJBeWENAVrse2ir5lFG5BCUSVAEteNtPjoswH7QNEvFYEqtUyucWltdxhDxY5AX02GRYCPSuf3d5HbaHg59noXbvSZ4kVR7zhCKL1VMgqxtvSAaew=\"}", 
		"Body={\"username\":\"{username_encrypted}\"}", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T04_VERIFYUSERNAME",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T04_VERIFYUSERNAME", LR_AUTO);
/*
	web_custom_request("enrollment_2", 
		"URL=https://202.162.16.159/v2/enrollment", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"grantType\":\"PASSWORD\",\"tokenType\":\"LOGIN\",\"username\":\"perftest127\",\"passwd\":\"nV+XqBkbw9nacOk6Di2JQD/jiI/zS5hZ0B5JZIR4Ablz/wuvvxD/f7DhRc+oDZbiVnO6zEMrYrgJ4HIKNNqIOojRzG7tWy1iVEfq2hA8crQs092gf4vYi7US/XS3YuClRdsUhPJP7RCloL7bcVkWYRsOv/adWuatJYAiVUgHUcY=\",\"mobileSDKData\":{\"deviceDetail\":\"Android\",\"deviceId\":\"k65v1_64_bsp\",\"deviceModel\":\"V2026\",\"deviceName\":\"V2026\",\"devicePrint\":\"string\",\"osType\":\"android\",\"osVersion\":\"30\",\"rsaKey\":\""
		"6F6E230ED02D01488DD521FD5204400A\",\"hardwareID\":\"04e04f7b-7c86-47b7-829e-8ba45e7f9d5a\",\"screenSize\":\"720x1475\",\"languages\":\"en\",\"multitaskingSupported\":true,\"timestamp\":\"\",\"geoLocationInfo\":{\"Latitude\":\"2.7291692\",\"Longitude\":\"102.0052373\",\"Status\":\"0\",\"Timestamp\":\"1687225268271\",\"HorizontalAccuracy\":\"12\"},\"emulator\":0,\"osId\":\"be681f3ff0c6e9db\",\"compromised\":0,\"sdkVersion\":\"4.4.0\",\"appState\":\"active\",\"keyChainErrorOnStoring\":\"NA\",\""
		"keyChainErrorOnRetrieve\":\"NA\"},\"limitApproved\":false}", 
		LAST);
*/
	web_add_header("authorization", "bearer {authToken}");
	
	web_reg_save_param_ex(
		"ParamName=accessToken",
		"LB=\"responseData\":{\"accessToken\":\"",
		"RB=\",\"refreshToken\":\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_find("Text=\"respCode\":\"DI200\",\"respDesc\":\"Success\"", LAST);
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T05_MDIPGENERATE");
	
	web_custom_request("generate",
		"URL=https://202.162.16.159/users/v1/mdip/generate", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T05_MDIPGENERATE",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T05_MDIPGENERATE", LR_AUTO);

	lr_think_time(tt);
	
//	web_reg_save_param_ex(
//		"ParamName=mobileNum",
//		"LB=\"mobileNo\":\"",
//		"RB=\",\"addr1\":\"",
//		SEARCH_FILTERS,
//		LAST);
	
	web_reg_save_param_ex(
		"ParamName=idNum",
		"LB=\"idNo\":\"",
		"RB=\",\"mobileNo\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=registeredName",
		"LB=\"customerName\":",
		"RB=,\"postCode\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=cifNo",
		"LB=\"gcif\":\"",
		"RB=\",\"onlineRegUrl\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=UniversalCifNo",
		"LB=\"universalCifNo\":\"",
		"RB=\",\"customerRiskRating\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=custIdentifier",
		"LB=\"custIdentifier\":",
		"RB=,\"idNo\":",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=mobIdentifier",
		"LB=\"mobIdentifer\":",
		"RB=,\"phoneTypeCode",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=officePhoneIdentifier",
		"LB=\"officePhoneIdentifier\":",
		"RB=,\"officeCity",
		SEARCH_FILTERS, 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=homeAddrIdentifier",
		"LB=\"homeAddrIdentifier\":",
		"RB=,\"officeStateCode",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=trxnRefNum",
		"LB=\"txRefNo\":\"",
		"RB=\",\"currentDate",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=empPhoneNum",
		"LB=\"employmentPhoneNumber\":\"",
		"RB=\",\"homeStateCode",
		SEARCH_FILTERS,
		LAST);
	
//	web_add_header("authorization", "bearer {authToken}");
	
	web_add_header("maya-authorization", "bearer {authToken}");
	
	web_add_header("authorization", "bearer {accessToken}");
	
	web_add_cookie("visid_incap_2853490=6jSdZSajR5Sxmg7p1YBdNGcEkWQAAAAAQUIPAAAAAABYummNzc6wNWAb2nbmzG6D; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("nlbi_2853490=PIu5QKX+fSdcP4SIeJDGsgAAAADpqvQEV/23ErGkFQ/Cm0xL; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("incap_ses_1136_2853490=ZLCABRkZDXhRvBFV9OLDD2cEkWQAAAAAfxvEgEa15KFAWrZK/YCVTg==; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_reg_find("Text=\"message\":\"Success\"", LAST);
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T06_CUSTOMERINQUIRYETB");
	
		web_custom_request("customerInquiryETB", 
//		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/customerInquiryETB",
		"URL=https://202.162.16.159/casa/openaccount/api/v1/customerInquiryETB", 		
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"idType\":\"\",\"birthDate\":\"\",\"preOrPostFlag\":\"postlogin\",\"icNo\":\"\",\"productName\":\"{productName}\"}", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T06_CUSTOMERINQUIRYETB",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T06_CUSTOMERINQUIRYETB", LR_AUTO);
	
	lr_think_time(tt);
	
	web_add_header("maya-authorization", "bearer {authToken}");
	
	web_add_header("authorization", "bearer {accessToken}");
	
	web_reg_save_param_ex(
		"ParamName=Code",
		"LB=\"code\":\"",
		"RB=\",\"type\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=accountNumber",
		"LB=\"number\":\"",
		"RB=0000000\",\"certs",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_find("Text=\"message\":\"success\"", LAST);

	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T07_SUMMARY");

	web_url("summary", 
		"URL=https://202.162.16.159/banking/v1/summary?type=A&checkMae=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T07_SUMMARY",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T07_SUMMARY", LR_AUTO);
	
	web_reg_save_param_ex(
		"ParamName=assessmentID",
		"LB=\"assessmentId\":\"",
		"RB=\",\"nextReviewDate",
		SEARCH_FILTERS,
		LAST);
	
//	web_add_header("maya-authorization", "bearer {authToken}");
//	
//	web_add_header("authorization", "bearer {accessToken}");
	
	web_add_cookie("visid_incap_2853490=6jSdZSajR5Sxmg7p1YBdNGcEkWQAAAAAQUIPAAAAAABYummNzc6wNWAb2nbmzG6D; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("nlbi_2853490=PIu5QKX+fSdcP4SIeJDGsgAAAADpqvQEV/23ErGkFQ/Cm0xL; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("incap_ses_1136_2853490=ZLCABRkZDXhRvBFV9OLDD2cEkWQAAAAAfxvEgEa15KFAWrZK/YCVTg==; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_reg_find("Text=\"message\":\"Success\"", LAST);

	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T08_SCOREPARTY");

	web_custom_request("scoreParty", 
//		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/scoreParty", 
		"URL=https://202.162.16.159/casa/openaccount/api/v1/scoreParty", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
//		"Body={\"statusCode\":\"0000\",\"statusDesc\":\"Success\",\"cifNo\":\"000723800\",\"cifCountryOfOnboarding\":\"MYS\",\"sourceSystem\":\"GCIF\",\"registeredName\":\"PUTERI ZARINA\",\"universalCifNo\":\"0000000004253497\",\"idTypeCode\":\"NWIC\",\"idTypeValue\":\"NEW IC\",\"custIdentifier\":444111,\"idNo\":\"980123146052\",\"idExpiryDate\":null,\"idIssuedCountryCode\":\"MYS\",\"idIssuedCountryValue\":\"MALAYSIA\",\"primaryDocument\":\"Y\",\"partyGroupCode\":\"BUM\",\"partyGroupValue\":\"BUMI\",\""
//		"salutationCode\":\"MSS\",\"salutationValue\":\"MS / CIK\",\"dateOfBirth\":\"23/01/1998\",\"raceCode\":\"MYS\",\"raceValue\":\"MALAY\",\"genderCode\":\"F\",\"genderValue\":\"FEMALE\",\"partyClassCode\":\"I\",\"partyClassValue\":\"INDIVIDUAL\",\"partyClassLegacyCode\":\"500\",\"partyClassLegacyValue\":\"PERSONAL (NON EXEMPTED GROUP)\",\"entityTypeCode\":\"12000\",\"entityTypeValue\":\"NON-EXEMPTED GROUP\",\"legalStructureCode\":\"INDV\",\"legalStructureValue\":\"INDIVIDUAL\",\"businessSizeCode\":\""
//		"NA\",\"businessSizeValue\":\"NOT APPLICABLE\",\"residentStatusCode\":\"CTZN\",\"residentStatusValue\":\"CITIZEN\",\"countryOfBirthCode\":\"MYS\",\"countryOfBirthValue\":\"MALAYSIA\",\"citizenshipCode\":\"MYS\",\"citizenshipValue\":\"MALAYSIA\",\"countryOfPermanentResidenceCode\":\"MYS\",\"countryOfPermanentResidenceValue\":\"MALAYSIA\",\"industrySectorCode\":\"97000\",\"industrySectorValue\":\"HOUSEHOLD\",\"mobAreaCode\":\"017\",\"mobPhoneNumber\":\"174347052\",\"noOfPhones\":1,\"mobPrimeInd\":\""
//		"Y\",\"mobIdentifer\":540497,\"phoneTypeCode\":\"\",\"phoneTypeValue\":\"MOBILE\",\"mobCountryCode\":\"+60\",\"mobDispCountryCode\":\"MALAYSIA (+60)\",\"mobDispCountryValue\":\"MALAYSIA (+60)\",\"email\":\"PERFTEST@GMAIL.COM\",\"pepDeclare\":false,\"occupationSectorCode\":\"H100002\",\"occupationSectorValue\":\"AVIATION/AEROSPACE\",\"occupationCode\":\"2411\",\"occupationValue\":\"ACCOUNTANTS\",\"grossIncomeRangeCode\":\"108\",\"grossIncomeRangeValue\":\"RM 6,000 TO RM 6,999\",\"employerName\":\""
//		"VERINON SOLUTIONS TECHNOLOGY\",\"employmentTypeCode\":\"PMP\",\"employmentTypeValue\":\"PRIVATE EMPLOYEE\",\"employmentPhoneNumber\":\"0184347052\",\"homeStateCode\":\"14011\",\"homeStateValue\":\"WP KUALA LUMPUR\",\"homeCountryCode\":\"MYS\",\"homeCountryValue\":\"MALAYSIA\",\"homePhonePrefix\":\"\",\"homePhoneNumber\":\"\",\"homePhoneIdentifier\":0,\"homeCity\":\"WP KUALA LUMPUR\",\"homeAddr1\":\"NO 102\",\"homeAddr2\":\"JALAN RK\",\"homeAddr3\":\"RASAH KEMAYAN\",\"homePostCode\":\"50100\",\""
//		"homeAddrFormat\":\"REST\",\"homeAddrTypeCode\":\"REST\",\"homeAddrTypeValue\":\"RESIDENTIAL\",\"homeAddrIdentifier\":472024,\"officeStateCode\":\"458001\",\"officeStateValue\":\"WP KUALA LUMPUR\",\"officeCountryCode\":\"MYS\",\"officeCountryValue\":\"MALAYSIA\",\"officePhonePrefix\":\"018\",\"officePhoneNumber\":\"4347052\",\"officePhoneIdentifier\":540496,\"officeCity\":\"WP KUALA LUMPUR\",\"officeAddr1\":\"NO 102\",\"officeAddr2\":\"JALAN KOMERSIAL\",\"officeAddr3\":\"CYBERKAYA\",\""
//		"officePostCode\":\"50100\",\"officeAddrFormat\":\"EYLR\",\"officeAddrTypeCode\":\"EYLR\",\"officeAddrTypeValue\":\"EMPLOYER\",\"officeAddrIdentifier\":472023,\"screeningStatusCode\":\"NOHITS\",\"screeningStatusValue\":\"No Watchlist hits \",\"customerRiskRatingCode\":\"LR\",\"customerRiskRatingValue\":\"LOW RISK\",\"screeningHits\":0,\"screeningId\":\"196077\",\"type\":\"individualParty\",\"noOfProducts\":3,\"countryOfOnboarding\":\"MYS\",\"consentForMarketing\":false,\"m2UIndicator\":false,\""
//		"onboardingStatusCode\":\"ACT\",\"onboardingStatusValue\":\"ACTIVE\",\"approvalStatusCode\":\"APPR\",\"approvalStatusValue\":\"Approved\",\"onboardingChannelCode\":\"FTF\",\"onboardingChannelValue\":\"FACE TO FACE\",\"onboardingTypeCode\":\"FULL\",\"onboardingTypeValue\":\"FULL\",\"countryOfOnboardingCode\":\"MYS\",\"countryOfOnboardingValue\":\"MALAYSIA\",\"createdBy\":\"MC010102\",\"createdDate\":\"16/05/2023\",\"lastUpdatedBy\":null,\"lastUpdatedDate\":\"16/05/2023\",\"homeBranchCode\":\"\",\""
//		"marketSegmentCode\":\"CFS\",\"marketSegmentValue\":\"CFS\",\"marketSubSegmentCode\":\"IND\",\"marketSubSegmentValue\":\"CFS - INDIVIDUAL\",\"marketSubSubSegmentCode\":\"NA\",\"marketSubSubSegmentValue\":\"NOT APPLICABLE\",\"customerSegmentCode\":\"\",\"customerSegmentValue\":\"\",\"vip\":false,\"staff\":false,\"products\":[{\"identifier\":126201,\"productCode\":{\"code\":\"101201\",\"value\":\"CASA\",\"selectable\":false},\"status\":\"APPROVED\"},{\"identifier\":126202,\"productCode\":{\"code\":\""
//		"101205\",\"value\":\"CASA - eWallet\",\"selectable\":false},\"status\":\"APPROVED\"},{\"identifier\":126203,\"productCode\":{\"code\":\"101207\",\"value\":\"MAE Debit Card\",\"selectable\":false},\"status\":\"APPROVED\"}],\"maritalStatusCode\":\"S\",\"maritalStatusValue\":\"SINGLE\",\"educationCode\":\"BCH\",\"educationValue\":\"BACHELOR\",\"religionCode\":\"ISLM\",\"religionValue\":\"ISLAM\",\"sourceOfFundCountry\":\"MYS\",\"sourceOfFundCountryValue\":\"MALAYSIA\",\"productName\":\"{productName}\""
//		",\"txRefNo\":\"STP23061517564692578\"}", 
		"Body={\"statusCode\":\"0000\",\"statusDesc\":\"Success\",\"cifNo\":\"{cifNo}\",\"cifCountryOfOnboarding\":\"MYS\",\"sourceSystem\":\"GCIF\",\"registeredName\":\"{registeredName}\",\"universalCifNo\":\"{UniversalCifNo}\",\"idTypeCode\":\"NWIC\",\"idTypeValue\":\"NEW IC\",\"custIdentifier\":{custIdentifier},\"idNo\":\"{idNum}\",\"idExpiryDate\":null,\"idIssuedCountryCode\":\"MYS\",\"idIssuedCountryValue\":\"MALAYSIA\",\"primaryDocument\":\"Y\",\"partyGroupCode\":\"BUM\",\"partyGroupValue\":\"BUMI\",\""
		"salutationCode\":\"MSS\",\"salutationValue\":\"MS / CIK\",\"dateOfBirth\":\"23/01/1998\",\"raceCode\":\"MYS\",\"raceValue\":\"MALAY\",\"genderCode\":\"F\",\"genderValue\":\"FEMALE\",\"partyClassCode\":\"I\",\"partyClassValue\":\"INDIVIDUAL\",\"partyClassLegacyCode\":\"500\",\"partyClassLegacyValue\":\"PERSONAL (NON EXEMPTED GROUP)\",\"entityTypeCode\":\"12000\",\"entityTypeValue\":\"NON-EXEMPTED GROUP\",\"legalStructureCode\":\"INDV\",\"legalStructureValue\":\"INDIVIDUAL\",\"businessSizeCode\":\""
		"NA\",\"businessSizeValue\":\"NOT APPLICABLE\",\"residentStatusCode\":\"CTZN\",\"residentStatusValue\":\"CITIZEN\",\"countryOfBirthCode\":\"MYS\",\"countryOfBirthValue\":\"MALAYSIA\",\"citizenshipCode\":\"MYS\",\"citizenshipValue\":\"MALAYSIA\",\"countryOfPermanentResidenceCode\":\"MYS\",\"countryOfPermanentResidenceValue\":\"MALAYSIA\",\"industrySectorCode\":\"97000\",\"industrySectorValue\":\"HOUSEHOLD\",\"mobAreaCode\":\"017\",\"mobPhoneNumber\":\"{mobileNum}\",\"noOfPhones\":1,\"mobPrimeInd\":\""
		"Y\",\"mobIdentifer\":{mobIdentifier},\"phoneTypeCode\":\"\",\"phoneTypeValue\":\"MOBILE\",\"mobCountryCode\":\"+60\",\"mobDispCountryCode\":\"MALAYSIA (+60)\",\"mobDispCountryValue\":\"MALAYSIA (+60)\",\"email\":\"PERFTEST@GMAIL.COM\",\"pepDeclare\":false,\"occupationSectorCode\":\"H100002\",\"occupationSectorValue\":\"AVIATION/AEROSPACE\",\"occupationCode\":\"2411\",\"occupationValue\":\"ACCOUNTANTS\",\"grossIncomeRangeCode\":\"108\",\"grossIncomeRangeValue\":\"RM 6,000 TO RM 6,999\",\"employerName\":\""
		"VERINON SOLUTIONS TECHNOLOGY\",\"employmentTypeCode\":\"PMP\",\"employmentTypeValue\":\"PRIVATE EMPLOYEE\",\"employmentPhoneNumber\":\"{empPhoneNum}\",\"homeStateCode\":\"14011\",\"homeStateValue\":\"WP KUALA LUMPUR\",\"homeCountryCode\":\"MYS\",\"homeCountryValue\":\"MALAYSIA\",\"homePhonePrefix\":\"\",\"homePhoneNumber\":\"\",\"homePhoneIdentifier\":0,\"homeCity\":\"WP KUALA LUMPUR\",\"homeAddr1\":\"NO 102\",\"homeAddr2\":\"JALAN RK\",\"homeAddr3\":\"RASAH KEMAYAN\",\"homePostCode\":\"50100\",\""
		"homeAddrFormat\":\"REST\",\"homeAddrTypeCode\":\"REST\",\"homeAddrTypeValue\":\"RESIDENTIAL\",\"homeAddrIdentifier\":{homeAddrIdentifier},\"officeStateCode\":\"458001\",\"officeStateValue\":\"WP KUALA LUMPUR\",\"officeCountryCode\":\"MYS\",\"officeCountryValue\":\"MALAYSIA\",\"officePhonePrefix\":\"018\",\"officePhoneNumber\":\"{empPhoneNum}\",\"officePhoneIdentifier\":{officePhoneIdentifier},\"officeCity\":\"WP KUALA LUMPUR\",\"officeAddr1\":\"NO 102\",\"officeAddr2\":\"JALAN KOMERSIAL\",\"officeAddr3\":\"CYBERKAYA\",\""
		"officePostCode\":\"50100\",\"officeAddrFormat\":\"EYLR\",\"officeAddrTypeCode\":\"EYLR\",\"officeAddrTypeValue\":\"EMPLOYER\",\"officeAddrIdentifier\":472023,\"screeningStatusCode\":\"NOHITS\",\"screeningStatusValue\":\"No Watchlist hits \",\"customerRiskRatingCode\":\"LR\",\"customerRiskRatingValue\":\"LOW RISK\",\"screeningHits\":0,\"screeningId\":\"196077\",\"type\":\"individualParty\",\"noOfProducts\":3,\"countryOfOnboarding\":\"MYS\",\"consentForMarketing\":false,\"m2UIndicator\":false,\""
		"onboardingStatusCode\":\"ACT\",\"onboardingStatusValue\":\"ACTIVE\",\"approvalStatusCode\":\"APPR\",\"approvalStatusValue\":\"Approved\",\"onboardingChannelCode\":\"FTF\",\"onboardingChannelValue\":\"FACE TO FACE\",\"onboardingTypeCode\":\"FULL\",\"onboardingTypeValue\":\"FULL\",\"countryOfOnboardingCode\":\"MYS\",\"countryOfOnboardingValue\":\"MALAYSIA\",\"createdBy\":\"MC010102\",\"createdDate\":\"16/05/2023\",\"lastUpdatedBy\":null,\"lastUpdatedDate\":\"16/05/2023\",\"homeBranchCode\":\"\",\""
		"marketSegmentCode\":\"CFS\",\"marketSegmentValue\":\"CFS\",\"marketSubSegmentCode\":\"IND\",\"marketSubSegmentValue\":\"CFS - INDIVIDUAL\",\"marketSubSubSegmentCode\":\"NA\",\"marketSubSubSegmentValue\":\"NOT APPLICABLE\",\"customerSegmentCode\":\"\",\"customerSegmentValue\":\"\",\"vip\":false,\"staff\":false,\"products\":[{\"identifier\":126201,\"productCode\":{\"code\":\"101201\",\"value\":\"CASA\",\"selectable\":false},\"status\":\"APPROVED\"},{\"identifier\":126202,\"productCode\":{\"code\":\""
		"101205\",\"value\":\"CASA - eWallet\",\"selectable\":false},\"status\":\"APPROVED\"},{\"identifier\":126203,\"productCode\":{\"code\":\"101207\",\"value\":\"MAE Debit Card\",\"selectable\":false},\"status\":\"APPROVED\"}],\"maritalStatusCode\":\"S\",\"maritalStatusValue\":\"SINGLE\",\"educationCode\":\"BCH\",\"educationValue\":\"BACHELOR\",\"religionCode\":\"ISLM\",\"religionValue\":\"ISLAM\",\"sourceOfFundCountry\":\"MYS\",\"sourceOfFundCountryValue\":\"MALAYSIA\",\"productName\":\"{productName}\""
		",\"txRefNo\":\"{trxnRefNum}\"}", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T08_SCOREPARTY",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T08_SCOREPARTY", LR_AUTO);
	
	lr_think_time(tt);
	
/*	
	web_custom_request("init_2", 
		"URL=https://202.162.16.159/2fa/v3/transaction/init", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"key\":\"nQaX5oRd8GmRwesxNEzfqy9MiGKCgxfUQ3xkMbgwIzEloerza3meqlD3V7hH/WabOtgdTNRfFTI2Ue25Uiy3bw5qKzfa8zbuSOHNjIAszWoMSYuLKLg/KrATXEQG02W3Gom9rJrI2Ef9us+BNFkXZMzMXnC6zVnoGYrEoIlbfvI=\",\"base64CipherText\":\"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\",\"tag\":\"52f59e7dedc4e7f28d1e88e4e528410f\",\"iv\":\"c23ee34737eaf44e2f2019bd\"}", 
		LAST);
*/
//	web_reg_save_param_ex(
//		"ParamName=tac",
//		"LB=\"token\":\"",
//		"RB=\",\"smsSentStatus",
//		SEARCH_FILTERS,
//		LAST);
	
//	web_add_header("authorization", "bearer {authToken}");
		
//	web_add_header("authorization", "bearer {accessToken}");
//	
//	web_add_cookie("visid_incap_2853490=6jSdZSajR5Sxmg7p1YBdNGcEkWQAAAAAQUIPAAAAAABYummNzc6wNWAb2nbmzG6D; DOMAIN=stp-engage.maybank2u.com.my");
//	
//	web_add_cookie("nlbi_2853490=PIu5QKX+fSdcP4SIeJDGsgAAAADpqvQEV/23ErGkFQ/Cm0xL; DOMAIN=stp-engage.maybank2u.com.my");
//	
//	web_add_cookie("incap_ses_1136_2853490=ZLCABRkZDXhRvBFV9OLDD2cEkWQAAAAAfxvEgEa15KFAWrZK/YCVTg==; DOMAIN=stp-engage.maybank2u.com.my");
//	
//	web_reg_find("Text=\"statusDesc\":\"Success\"", LAST);
//
//	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_REQUEST_TAC");
//	
//	web_custom_request("requestTACETB",
////		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/requestTACETB", 
//		"URL=https://202.162.16.159/casa/openaccount/api/v1/requestTACETB", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=", 
//		"Snapshot=t17.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
////		"Body={\"mobileNo\":\"60174347052\",\"otp\":\"\",\"idNo\":\"980123146052\",\"transactionType\":\"CASA_STP\",\"preOrPostFlag\":\"postlogin\",\"productName\":\"{productName}\"}", 
//		"Body={\"mobileNo\":\"{mobileNum}\",\"otp\":\"\",\"idNo\":\"{idNum}\",\"transactionType\":\"CASA_STP\",\"preOrPostFlag\":\"postlogin\",\"productName\":\"{productName}\"}", 
//		LAST);
//
//	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_REQUEST_TAC",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
//	
//	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_REQUEST_TAC", LR_AUTO);
//	
//	lr_think_time(tt);
	
	web_reg_find("Text=\"message\":\"Success\"", LAST);

	web_add_header("maya-authorization", "bearer {authToken}");
		
	web_add_header("authorization", "bearer {accessToken}");
	
	web_add_cookie("visid_incap_2853490=6jSdZSajR5Sxmg7p1YBdNGcEkWQAAAAAQUIPAAAAAABYummNzc6wNWAb2nbmzG6D; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("nlbi_2853490=PIu5QKX+fSdcP4SIeJDGsgAAAADpqvQEV/23ErGkFQ/Cm0xL; DOMAIN=stp-engage.maybank2u.com.my");
	
	web_add_cookie("incap_ses_1136_2853490=ZLCABRkZDXhRvBFV9OLDD2cEkWQAAAAAfxvEgEa15KFAWrZK/YCVTg==; DOMAIN=stp-engage.maybank2u.com.my");
	
	lr_start_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_ACTIVATE_CASAACCOUNT_ETB");
	
	web_custom_request("activateCasaAccountETB", 
//		"URL=https://stp-engage.maybank2u.com.my/casa/openaccount/api/v1/activateCasaAccountETB", 
		"URL=https://202.162.16.159/casa/openaccount/api/v1/activateCasaAccountETB", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
//		"Body={\"activateAccountReq\":{\"idType\":\"01\",\"customerEmail\":\"PERFTEST@GMAIL.COM\",\"customerName\":\"PUTERI ZARINA\",\"mobileNo\":\"+60174347052\",\"idNo\":\"980123146052\",\"preOrPostFlag\":\"postlogin\",\"nationality\":\"MALAYSIA\",\"pdpa\":\"Y\",\"transactionType\":null,\"referalCode\":null,\"addr1\":\"NO 102\",\"addr2\":\"JALAN RK\",\"addr3\":\"RASAH KEMAYAN\",\"custStatus\":\"0\",\"m2uIndicator\":\"1\",\"pan\":null,\"postCode\":\"50100\",\"state\":\"14011\",\"stateValue\":\"WP KUALA "
//		"LUMPUR\",\"fatcaStateValue\":\"Y\",\"ekycRefId\":null,\"empType\":\"PMP\",\"empTypeValue\":\"PRIVATE EMPLOYEE\",\"occupation\":\"2411\",\"occupationValue\":\"ACCOUNTANTS\",\"employerName\":\"VERINON SOLUTIONS TECHNOLOGY\",\"sector\":\"H100002\",\"sectorValue\":\"AVIATION/AEROSPACE\",\"gender\":\"F\",\"genderValue\":\"FEMALE\",\"passportExpiry\":null,\"issuedCountry\":\"MYS\",\"issuedCountryValue\":\"MALAYSIA\",\"title\":\"MSS\",\"titleValue\":\"MS / CIK\",\"race\":\"MYS\",\"raceValue\":\"MALAY\","
//		"\"pep\":\"no\",\"city\":\"WP KUALA LUMPUR\",\"monthlyIncomeRange\":\"108\",\"monthlyIncomeRangeValue\":\"RM 6,000 TO RM 6,999\",\"sourceOfFundCountry\":\"MYS\",\"sourceOfFundCountryValue\":\"MALAYSIA\",\"riskRating\":null,\"declarePdpaPromotion\":\"Y\",\"tc\":\"Y\",\"purpose\":null,\"preferredBRDistrict\":\"Kuala Lumpur\",\"preferredBRState\":\"WP KUALA LUMPUR\",\"preferredBranch\":\"14011\",\"preferredBranchValue\":\"KUALA LUMPUR MAIN\",\"saFormInvestmentExp\":\"No\",\"saFormInvestmentNature\":\""
//		"No\",\"saFormInvestmentRisk\":\"No\",\"saFormInvestmentTerm\":\"No\",\"saFormPIDM\":\"Agree\",\"saFormProductFeature\":\"Agree\",\"saFormSecurities\":\"No\",\"saFormSuitability\":\"Agree\",\"onBoardingStatusInfo\":\"ACTIVE\",\"isZestI\":null,\"customerRiskRating\":\"LR\",\"customerRiskRatingValue\":\"LOW RISK\",\"accountNumber\":null,\"assessmentId\":\"1768863\",\"screeningId\":\"196077\",\"sanctionsTagging\":\"NON\",\"sanctionsTaggingValue\":\"NON\",\"gcif\":\"000723800\",\"universalCifNo\":\""
//		"0000000004253497\",\"primBitMap\":null,\"numOfWatchlistHits\":0,\"sourceOfFund\":null,\"sourceOfFundValue\":null,\"sourceOfWealth\":null,\"sourceOfWealthValue\":null,\"nextReviewDate\":\"\",\"finanicalObjective\":null,\"finanicalObjectiveValue\":null,\"staffInd\":null,\"homeAddrIdentifier\":472024,\"existingCasaAccount\":\"114013986531\",\"fromAccountCode\":\"11\",\"mobIdentifer\":540497,\"transferAmount\":\"10.00\",\"txRefNo\":\"STP23061517564692578\",\"productName\":\"{productName}\"},\"otpInput"
//		"\":\"{\\\"mobileNo\\\":\\\"60174347052\\\",\\\"idNumber\\\":\\\"980123146052\\\",\\\"otp\\\":\\\"676531\\\",\\\"transactionType\\\":\\\"CASA_STP_VERIFY\\\",\\\"preOrPostFlag\\\":\\\"postlogin\\\",\\\"idNo\\\":\\\"980123146052\\\",\\\"productName\\\":\\\"{productName}\\\"}\"}", 
//		"Body={\"activateAccountReq\":{\"idType\":\"01\",\"customerEmail\":\"PERFTEST@GMAIL.COM\",\"customerName\":\"{registeredName}\",\"mobileNo\":\"{mobileNum}\",\"idNo\":\"{idNum}\",\"preOrPostFlag\":\"postlogin\",\"nationality\":\"MALAYSIA\",\"pdpa\":\"Y\",\"transactionType\":null,\"referalCode\":null,\"addr1\":\"NO 102\",\"addr2\":\"JALAN RK\",\"addr3\":\"RASAH KEMAYAN\",\"custStatus\":\"0\",\"m2uIndicator\":\"1\",\"pan\":null,\"postCode\":\"50100\",\"state\":\"14011\",\"stateValue\":\"WP KUALA "
//		"LUMPUR\",\"fatcaStateValue\":\"Y\",\"ekycRefId\":null,\"empType\":\"PMP\",\"empTypeValue\":\"PRIVATE EMPLOYEE\",\"occupation\":\"2411\",\"occupationValue\":\"ACCOUNTANTS\",\"employerName\":\"VERINON SOLUTIONS TECHNOLOGY\",\"sector\":\"H100002\",\"sectorValue\":\"AVIATION/AEROSPACE\",\"gender\":\"F\",\"genderValue\":\"FEMALE\",\"passportExpiry\":null,\"issuedCountry\":\"MYS\",\"issuedCountryValue\":\"MALAYSIA\",\"title\":\"MSS\",\"titleValue\":\"MS / CIK\",\"race\":\"MYS\",\"raceValue\":\"MALAY\","
//		"\"pep\":\"no\",\"city\":\"WP KUALA LUMPUR\",\"monthlyIncomeRange\":\"108\",\"monthlyIncomeRangeValue\":\"RM 6,000 TO RM 6,999\",\"sourceOfFundCountry\":\"MYS\",\"sourceOfFundCountryValue\":\"MALAYSIA\",\"riskRating\":null,\"declarePdpaPromotion\":\"Y\",\"tc\":\"Y\",\"purpose\":null,\"preferredBRDistrict\":\"Kuala Lumpur\",\"preferredBRState\":\"WP KUALA LUMPUR\",\"preferredBranch\":\"14011\",\"preferredBranchValue\":\"KUALA LUMPUR MAIN\",\"saFormInvestmentExp\":\"No\",\"saFormInvestmentNature\":\""
//		"No\",\"saFormInvestmentRisk\":\"No\",\"saFormInvestmentTerm\":\"No\",\"saFormPIDM\":\"Agree\",\"saFormProductFeature\":\"Agree\",\"saFormSecurities\":\"No\",\"saFormSuitability\":\"Agree\",\"onBoardingStatusInfo\":\"ACTIVE\",\"isZestI\":null,\"customerRiskRating\":\"LR\",\"customerRiskRatingValue\":\"LOW RISK\",\"accountNumber\":null,\"assessmentId\":\"{assessmentID}\",\"screeningId\":\"196077\",\"sanctionsTagging\":\"NON\",\"sanctionsTaggingValue\":\"NON\",\"gcif\":\"{cifNo}\",\"universalCifNo\":\""
//		"{UniversalCifNo}\",\"primBitMap\":null,\"numOfWatchlistHits\":0,\"sourceOfFund\":null,\"sourceOfFundValue\":null,\"sourceOfWealth\":null,\"sourceOfWealthValue\":null,\"nextReviewDate\":\"\",\"finanicalObjective\":null,\"finanicalObjectiveValue\":null,\"staffInd\":null,\"homeAddrIdentifier\":{homeAddrIdentifier},\"existingCasaAccount\":\"{accountNumber}\",\"fromAccountCode\":\"{Code}\",\"mobIdentifer\":{mobIdentifier},\"transferAmount\":\"10.00\",\"txRefNo\":\"{trxnRefNum}\",\"productName\":\"{productName}\"},\"otpInput"
//		"\":\"{\\\"mobileNo\\\":\\\"{mobileNum}\\\",\\\"idNumber\\\":\\\"{idNum}\\\",\\\"otp\\\":\\\"{tac}\\\",\\\"transactionType\\\":\\\"CASA_STP_VERIFY\\\",\\\"preOrPostFlag\\\":\\\"postlogin\\\",\\\"idNo\\\":\\\"{idNum}\\\",\\\"productName\\\":\\\"{productName}\\\"}\"}", 
		"Body={\"activateAccountReq\":{\"idType\":\"01\",\"customerEmail\":\"PERFTEST@GMAIL.COM\",\"customerName\":\"{registeredName}\",\"mobileNo\":\"{mobileNum}\",\"idNo\":\"{idNum}\",\"preOrPostFlag\":\"postlogin\",\"nationality\":\"MALAYSIA\",\"pdpa\":\"Y\",\"transactionType\":null,\"referalCode\":null,\"addr1\":\"NO 102\",\"addr2\":\"JALAN RK\",\"addr3\":\"RASAH KEMAYAN\",\"custStatus\":\"0\",\"m2uIndicator\":\"1\",\"pan\":null,\"postCode\":\"50100\",\"state\":\"14011\",\"stateValue\":\"WP KUALA "
		"LUMPUR\",\"fatcaStateValue\":\"Y\",\"ekycRefId\":null,\"empType\":\"PMP\",\"empTypeValue\":\"PRIVATE EMPLOYEE\",\"occupation\":\"2411\",\"occupationValue\":\"ACCOUNTANTS\",\"employerName\":\"VERINON SOLUTIONS TECHNOLOGY\",\"sector\":\"H100002\",\"sectorValue\":\"AVIATION/AEROSPACE\",\"gender\":\"F\",\"genderValue\":\"FEMALE\",\"passportExpiry\":null,\"issuedCountry\":\"MYS\",\"issuedCountryValue\":\"MALAYSIA\",\"title\":\"MSS\",\"titleValue\":\"MS / CIK\",\"race\":\"MYS\",\"raceValue\":\"MALAY\","
		"\"pep\":\"no\",\"city\":\"WP KUALA LUMPUR\",\"monthlyIncomeRange\":\"108\",\"monthlyIncomeRangeValue\":\"RM 6,000 TO RM 6,999\",\"sourceOfFundCountry\":\"MYS\",\"sourceOfFundCountryValue\":\"MALAYSIA\",\"riskRating\":null,\"declarePdpaPromotion\":\"Y\",\"tc\":\"Y\",\"purpose\":null,\"preferredBRDistrict\":\"Kuala Lumpur\",\"preferredBRState\":\"WP KUALA LUMPUR\",\"preferredBranch\":\"14011\",\"preferredBranchValue\":\"KUALA LUMPUR MAIN\",\"saFormInvestmentExp\":\"No\",\"saFormInvestmentNature\":\""
		"No\",\"saFormInvestmentRisk\":\"No\",\"saFormInvestmentTerm\":\"No\",\"saFormPIDM\":\"Agree\",\"saFormProductFeature\":\"Agree\",\"saFormSecurities\":\"No\",\"saFormSuitability\":\"Agree\",\"onBoardingStatusInfo\":\"ACTIVE\",\"isZestI\":null,\"customerRiskRating\":\"LR\",\"customerRiskRatingValue\":\"LOW RISK\",\"accountNumber\":null,\"assessmentId\":\"{assessmentID}\",\"screeningId\":\"196077\",\"sanctionsTagging\":\"NON\",\"sanctionsTaggingValue\":\"NON\",\"gcif\":\"{cifNo}\",\"universalCifNo\":\""
		"{UniversalCifNo}\",\"primBitMap\":null,\"numOfWatchlistHits\":0,\"sourceOfFund\":null,\"sourceOfFundValue\":null,\"sourceOfWealth\":null,\"sourceOfWealthValue\":null,\"nextReviewDate\":\"\",\"finanicalObjective\":null,\"finanicalObjectiveValue\":null,\"staffInd\":null,\"homeAddrIdentifier\":{homeAddrIdentifier},\"existingCasaAccount\":\"{accountNumber}\",\"fromAccountCode\":\"{Code}\",\"mobIdentifer\":{mobIdentifier},\"transferAmount\":\"10.00\",\"txRefNo\":\"{trxnRefNum}\",\"productName\":\"{productName}\"},\"otpInput"
		"\":\"{\\\"mobileNo\\\":\\\"{mobileNum}\\\",\\\"idNumber\\\":\\\"{idNum}\\\",\\\"transactionType\\\":\\\"CASA_STP_VERIFY\\\",\\\"preOrPostFlag\\\":\\\"postlogin\\\",\\\"idNo\\\":\\\"{idNum}\\\",\\\"productName\\\":\\\"{productName}\\\"}\"}", 
		LAST);

	TransStat("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_ACTIVATE_CASAACCOUNT_ETB",lr_eval_string("{username}"),lr_eval_string("{IterationNum}"));
	
	lr_end_transaction("BP01_MAE_CASA_STP_SIMPLIFICATION_T09_ACTIVATE_CASAACCOUNT_ETB", LR_AUTO);
	
	return 0;
}