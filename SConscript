# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/CalUtil/SConscript,v 1.16 2012/05/18 21:44:15 chehtman Exp $
# Authors: Alexandre Chekhtman
# Version: CalUtil-03-14-08
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='CalUtil', toBuild='shared')

CalUtil = libEnv.SharedLibrary('CalUtil',
                               listFiles(['src/*.cxx',
                                          'src/SimpleCalCalib/*.cxx']))

progEnv.Tool('CalUtilLib')
progEnv.AppendUnique(CPPDEFINES = ['PACKAGE_NAME=\\"CalUtil\\"'])

test_CalUtil = progEnv.Program('test_CalUtil',
                               ['src/test/test_CalUtil.cxx'])

progEnv.Tool('registerTargets', package = 'CalUtil',
             libraryCxts = [[CalUtil, libEnv]],
             testAppCxts = [[test_CalUtil, progEnv]], 
             includes = listFiles(['CalUtil/*'], recursive = 1),
             xml = ['xml/idealCalib_flight.xml', 'xml/idealCalib_muon.xml'])




