# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/SConscript,v 1.5 2008/11/11 17:15:50 ecephas Exp $
# Authors: 
# Version: CalUtil-03-13-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('CalUtilLib', depsOnly = 1)

CalUtil = libEnv.SharedLibrary('CalUtil', listFiles(['src/*.cxx']) + listFiles(['src/SimpleCalCalib/*.cxx']))

progEnv.Tool('CalUtilLib')
test_CalUtil = progEnv.Program('test_CalUtil', ['src/test/test_CalUtil.cxx'])

progEnv.Tool('registerObjects', package = 'CalUtil', libraries = [CalUtil], testApps = [test_CalUtil], 
		includes = listFiles(['CalUtil/*'], recursive = 1))



