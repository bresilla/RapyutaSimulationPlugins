# Configuration file for the Sphinx documentation builder.

import os
import subprocess

# import sys

print("****************************************")
print("conf.py")
print("****************************************")

read_the_docs_build = os.environ.get("READTHEDOCS", None) == "True"
# if read_the_docs_build:
#    pass
# else :
#    pass
# sys.path.append( "/usr/local/lib/python3.9/site-packages/breathe/" )

# -- Doxygen and breath
subprocess.call("mkdir -p ../../_readthedocs/html/; cd ..; doxygen", shell=True)
breathe_projects = {
    "RapyutaSimulationPlugins": "../../_readthedocs/html/doxygen_generated/xml"
}
# breathe_projects_source = {
#      "auto" : ( "../Private/RapyutaSimulationPlugins", ["*.h"] )
#      }
breathe_default_project = "RapyutaSimulationPlugins"

# -- Project information

project = "RapyutaSimulationPlugins"
copyright = "2022, Rapyuta Robotics"
author = "Rapyuta Robotics"

release = "0.1"
version = "0.1.0"

# -- General configuration

extensions = [
    "sphinx.ext.duration",
    "sphinx.ext.doctest",
    "sphinx.ext.autodoc",
    "sphinx.ext.autosummary",
    "sphinx.ext.intersphinx",
    "sphinx.ext.imgmath",
    "sphinx.ext.todo",
    "breathe",
    "sphinx.ext.graphviz",
    "myst_parser",
    "sphinxcontrib.video",
    "sphinxcontrib.youtube",
]

intersphinx_mapping = {
    "python": ("https://docs.python.org/3/", None),
    "sphinx": ("https://www.sphinx-doc.org/en/master/", None),
}
intersphinx_disabled_domains = ["std"]

templates_path = ["_templates"]

exclude_patterns = ["api"]
# -- Options for HTML output

html_theme = "sphinx_rtd_theme"
# html_style = 'css/style.css'
html_static_path = ["_static"]

# -- Options for EPUB output
epub_show_urls = "footnote"

# html_extra_path = ['../html']

source_suffix = {
    ".rst": "restructuredtext",
    ".md": "markdown",
}


def setup(app):
    app.add_css_file("css/style.css")
