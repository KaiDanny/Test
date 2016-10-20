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
    
    <title>My JSP 'simpletag.jsp' starting page</title>
    
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
    <%
    	List<Customer> customers = new ArrayList<Customer>();
    	customers.add(new Customer(1,"aa",12));
    	customers.add(new Customer(2,"aa",13));
    	customers.add(new Customer(3,"aa",14));
    	customers.add(new Customer(4,"aa",15));
    	customers.add(new Customer(5,"aa",16));
    	request.setAttribute("customers", customers);
     %>
     <jsp:forward page="testtag.jsp"></jsp:forward>
  </body>
</html>
