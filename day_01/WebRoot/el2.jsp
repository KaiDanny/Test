<%@page import="com.lkd.Customer"%>
<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'el2.jsp' starting page</title>
    
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
  	<!-- 7.EL的关系运算符 -->
  	${param.score > 60 ? "及格":"不及格" }
  	<br>
  	<%
  		List<String> names = new ArrayList<String>();
  		names.add("abc");
  		request.setAttribute("names", names);
  	 %>
  	 <!-- empty 可以作用于一个结合，若该集合不存在或者集合中没有元素,其结果都为true -->
  	 name is empty:${empty requestScope.names }
  	 <br>
  	<!-- 隐含对象之与范围相关的:pageScope,requestScope,sessionScope,applicationScope -->
	<!-- 其他隐含对象:pageContext等(cookie,header,initParam只需了解 -->
  	pageContext:pageContext即为PageContext类型，但只能读取属性
  	<br>
  	contextPath:${pageContext.request.contextPath }
  	<br>
  	sessionId:${pageContext.session.id }
  	<br>
  	sessionAttributeNames:${pageContext.session.attributeNames }
  	<br>
  	<!-- 获取当前web站台的环境参数 -->
  	initParam:${initParam.initName }
  	<br>
  	JSESSIONID:${cookie.JSESSIONID.value }
  	<br>
  	time:${applicationScope.time }
  	<br>
  	 <!-- EL可以进行自动的类型转换 -->
  	score: ${param.score + 11 }
  	<br>
  	names:${paramValues.name[0] }
  	<%=
  		request.getParameterValues("name")[0].getClass().getName()
  	 %>
  	<br>
  	score:<%=request.getParameter("score")+11 %>
  	<%
  		Customer cust2 = new Customer();
  		cust2.setAge(28);
  		request.setAttribute("customer", cust2);
  	 %>
    age:${customer.age}
    <br>
    age2:${sessionScope.customer["age"]}
    <br>
    age3:
    <%--
	    <%
	    	Customer customer = (Customer)session.getAttribute("customer");
	    	out.print(customer.getAge());
	     %>    
     --%>

     <%
     	Customer customer = new Customer();
     	customer.setName("lkd");
     	session.setAttribute("com.lkd.Customer", customer);
      %>
      name:${sessionScope["com.lkd.Customer"].name}
  </body>
</html>
