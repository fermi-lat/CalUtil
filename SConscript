# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/SConscript,v 1.2 2008/09/23 15:30:10 glastrm Exp $
# Authors: 
# Version: CalUtil-03-14-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('CalUtilLib', depsOnly = 1)

CalUtil = libEnv.SharedLibrary('CalUtil', listFiles(['src/*.cxx']) + listFiles(['src/SimpleCalCalib/*.cxx']))

progEnv.Tool('CalUtilLib')
test_CalUtil = progEnv.Program('test_CalUtil', listFiles(['src/test/*.cxx']))

progEnv.Tool('registerObjects', package = 'CalUtil', libraries = [CalUtil], testApps = [test_CalUtil], includes = listFiles(['CalUtil/*.h']) + listFiles(['CalUtil/SimpleCalCalib/*.h']))
