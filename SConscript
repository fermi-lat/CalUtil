# -*- python -*-
# $Header$
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
test_CalUtil = progEnv.GaudiProgram('test_CalUtil', listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerObjects', package = 'CalUtil', libraries = [CalUtil], testApps = [test_CalUtil], includes = listFiles(['CalUtil/*.h']) + listFiles(['CalUtil/SimpleCalCalib/*.h']))