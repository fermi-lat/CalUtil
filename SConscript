# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/SConscript,v 1.7 2009/01/23 00:06:50 ecephas Exp $
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

progEnv.Tool('registerTargets', package = 'CalUtil',
             libraryCxts = [[CalUtil, libEnv]],
             testAppCxts = [[test_CalUtil, progEnv]], 
             includes = listFiles(['CalUtil/*'], recursive = 1))




