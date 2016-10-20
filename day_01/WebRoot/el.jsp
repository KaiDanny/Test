<%@page import="com.lkd.Customer"%>
<%@ page language="java" import="java.util.*" pageEncoding="ISO-8859-1"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'el.jsp' starting page</title>
    
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
    <form action="el.jsp" method="post">
    name:<input type="text" name="name" value="${param.name}">
    <input type="submit" name="submit">
    </form>
    username:<%=request.getParameter("name")%>
    <br><br>
    <jsp:useBean id="customer" class="com.lkd.Customer" scope="session"></jsp:useBean>
    <jsp:setProperty property="age" value="12" name="customer"/>
    age:
    <%
    	Customer customer2=(Customer)session.getAttribute("customer");
    	out.print(customer2.getAge());
     %>
     <%
     	application.setAttribute("time", new Date());
      %>
     <a href="el2.jsp?score=89&name=A&name=B&name=C">To El2 page</a>
  </body>
</html>
