#----------------------------------------------------------------------------
#       Make Workspace
#
# $Id: MakeWorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/hilljh/MPC/mwc.pl -type make /home/hilljh/sandbox/cs363/assignment3/jcortesv/cs363-spring2024-assignment3
#
#----------------------------------------------------------------------------


all: assignment3

clean depend generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignment3 $(@)

.PHONY: assignment3
assignment3:
	@$(MAKE) -f Makefile.assignment3 all

project_name_list:
	@echo assignment3
