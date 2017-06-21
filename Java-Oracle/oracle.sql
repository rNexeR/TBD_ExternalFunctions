CREATE OR REPLACE
FUNCTION  BIN2DEC(binary nvarchar2) RETURN NUMBER AS language JAVA
name 'Functions.BIN2DEC(java.lang.String) return java.lang.Integer';
 
CREATE OR REPLACE
FUNCTION  C2F(n NUMBER) RETURN NUMBER AS language JAVA
name 'Functions.C2F(double) return java.lang.Double';
 
CREATE OR REPLACE
FUNCTION  DEC2BIN(n NUMBER) RETURN nvarchar2 AS language JAVA
name 'Functions.DEC2BIN(int) return java.lang.String';
 
CREATE OR REPLACE
FUNCTION  DEC2HEX(n NUMBER) RETURN nvarchar2 AS language JAVA
name 'Functions.DEC2HEX(int) return java.lang.String';
 
CREATE OR REPLACE
FUNCTION  F2C(n NUMBER) RETURN NUMBER AS language JAVA
name 'Functions.F2C(double) return java.lang.Double';
 
CREATE OR REPLACE
FUNCTION  FACTORIAL(n NUMBER) RETURN NUMBER AS language JAVA
name 'Functions.Factorial(int) return java.lang.Integer';
 
CREATE OR REPLACE
FUNCTION  HEX2DEC(n nvarchar2) RETURN NUMBER AS language JAVA
name 'Functions.HEX2DEC(java.lang.String) return java.lang.Integer';
 
CREATE OR REPLACE
FUNCTION  PING(url VARCHAR2) RETURN NUMBER AS language JAVA
name 'Functions.Ping(java.lang.String) return java.lang.Integer';
 
CREATE OR REPLACE
FUNCTION  PMT(tasa NUMBER, n NUMBER, prestamo NUMBER) RETURN NUMBER AS language JAVA
name 'Functions.PMT(double, int, double) return java.lang.Double';
 
CREATE OR REPLACE
FUNCTION  REPEAT(n nvarchar2, n2 NUMBER) RETURN nvarchar2 AS language JAVA
name 'Functions.Repeat(java.lang.String, int) return java.lang.String';
 
CREATE OR REPLACE
FUNCTION  STRTRIM(n nvarchar2, n2 nvarchar2) RETURN nvarchar2 AS language JAVA
name 'Functions.StrTrim(java.lang.String, java.lang.String) return java.lang.String';