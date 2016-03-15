.. w3gal documentation master file, created by
   sphinx-quickstart on Thu Apr 23 06:15:19 2015.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

w3gal
=====

An ATL Server based web-server for hosting ATL Server Web applications on the Windows for Iot Platform

W3Gal can be used in place of IIS and ISAPI to host your ATL Server Web Apps. For more information on ATL Server, please see http://msdn.microsoft.com/en-us/library/exb5b09w(v=vs.80).aspx and http://atlserver.codeplex.com/ Think of w3gal as an interface between ATL Server and the HTTP Api.
You may also use W3Gal to serve up static content. SSL is also supported.
View http://w3gal.info/changelog.txt - 1068 bytes

Download http://w3gal.info/w3gal.exe - 172 KB

Usage
-----

::

    W3Gal.exe <pathinfo> OPTIONS


Where pathinfo is the path info that clients will include in an http request. This directory must be a underneath the directory that W3Gal.exe is located in. ie. c:\\test\\cgi-bin if you placed w3gal.exe in the c:\\test directory.
For example, suppose you create an ATL Server web application called HelloWorld.dll and place it in the c:\\test\\cgi-bin directory and would like W3Gal.exe to map requests like this http://mygalileo/cgi-bin/HelloWorld.srf::

    c:\test>W3Gal.exe cgi-bin

The cgi-bin argument must match the path info in the URI. Any static requests must include the cgi-bin pathinfo eg. http://mygalileo/cgi-bin/index.htm

ATL Server Request Handlers
---------------------------

Consult http://msdn.microsoft.com/en-us/library/exb5b09w(v=vs.80).aspx for information on ATL Server first. 
ATL Server caches your web applications by default (.dll and .srf files). You may use relative paths inside your .srf file by using the {{include}} directive. For example::

    {{include ..\hello.txt}}

will include the text file in the directory above the .srf file.
Exceptions in your web-application may cause w3gal to terminate.

Options
-------

::

    c:\test>W3Gal.exe cgi-bin /s

Will start w3gal using ssl support (but you must set up ssl first, see :ref:`ssl`)

Details
-------

- w3gal is a replacement for IIS on the Windows for IOT platform. 
- You may also use it on Windows 8 
- It handles http byte-range requests.
- w3gal is synchronous in nature (ie. you cannot have 2 clients downloading data at the same time - only 1 is allowed).
- Only HTTP Get, Head requests are supported for static files, but if you use an atl server request handler, you can use any method you want.
- HTTP headers are available to your atl server request handler, as well as several extensions. See :ref:`http-headers` for more information.
- Currently w3gal uses a text based buffer for handling ATL Server requests. Keep this in mind if you decide to try and use an ATL Server request handler to send binary data: it may not work very fast.
- You can create ATL Server request handlers using Visual Studio 2003 or 2005, but you must upgrade them to Visual Studio 2013 projects for re-compiling and debugging on the Windows for IOT platform. An easier method is to download one of the sample projects and rename it. Another method is described in :ref:`atl-server-projects`
- w3gal uses 620KB of ram. Once you load your ATL Server Request handler, the usage will grow since the dll is mapped into w3gal's memory. Static files will also be loaded into RAM temporarily - don't try to send down a file that's over 256MB in size or else w3gal will run out of memory (at least on the Intel Galileo).
- I have tested w3gal with IPv6 and it is working, but not with SSL.
- HTTP errors will be logged to the console
.. image:: _images\console.png



Contents
--------

.. toctree::
   :maxdepth: 2

   w3gal
   debugging
   ssl
   http-headers
   performance
   atl-server-projects
   samples


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

Contact Info
============

ryan.beckett@hotmail.com
