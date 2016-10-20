<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'books.jsp' starting page</title>
    
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
    <h4>Books page</h4>
    <a href="book.jsp?book=JavaWeb">Java Web</a><br><br>
    <a href="book.jsp?book=Java">Java</a><br><br>
    <a href="book.jsp?book=Oracle">Oracle</a><br><br>
    <a href="book.jsp?book=Ajax">Ajax</a><br><br>
    <a href="book.jsp?book=JavaScript">JavaScript</a><br><br>
    <a href="book.jsp?book=Anroid">Anroid</a><br><br>
    <a href="book.jsp?book=Jbpm">Jbpm</a><br><br>
    <a href="book.jsp?book=Struts">Struts</a><br><br>
    <a href="book.jsp?book=Hibernate">Hibernate</a><br><br>
    <a href="book.jsp?book=Spring">Spring</a><br><br>
    <br><br>
    <%
    	//显示最近浏览的5本书
    	//获取所有的cookie
    	Cookie[] cookies = request.getCookies();
    	//从中筛选出Book的Cookie:如果cookieName为aa开头符合条件
		if(cookies != null&&cookies.length > 0){
    		for(Cookie c: cookies){
    			String cookieName = c.getName();
    			if(cookieName.startsWith("aa")){
					out.println(c.getValue());
					out.println("<br>");
    			}
    		}
    	}    	
     %>
  </body>
</html>
