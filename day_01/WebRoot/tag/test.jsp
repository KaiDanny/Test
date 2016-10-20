<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<!-- 导入标签库文件 -->
<%@taglib uri="http://www.lkd.com/mytag/core" prefix="lkd"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'test.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
  	<lkd:readerFile src="/WEB-INF/sql.txt"/>
  	<lkd:max num2="${param.a }" num1="${param.b }"/>
  	
  	<br>
    <lkd:hello value="${param.name }" count="10"/>
  </body>
</html>
