 import sys
 import os
 #import shlex
 import sphinx_rtd_theme
 #sys.path.insert(0, os.path.abspath('.'))
 extensions = []
 templates_path = ['_templates']
 source_suffix = ['.rst', '.md']
 master_doc = 'w3gal'
 project = u'w3gal'
 copyright = u'2015, Ryan Beckett'
 author = u'ryan.beckett@hotmail.com'
 version = '1'
 release = '1'
 language = None
 exclude_patterns = ['_build']
 pygments_style = 'sphinx'
 todo_include_todos = False
 html_theme = 'sphinx_rtd_theme'
 html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
 html_title = "w3gal webserver for windows iot devices"
 html_static_path = ['_static']
 html_show_sourcelink = True
 latex_elements = {
 }
 latex_documents = [
  (master_doc, 'w3gal.tex', u'Test Documentation',
   u'Test', 'manual'),
]
