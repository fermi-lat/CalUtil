#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/CalUtilLib.py,v 1.3 2008/11/12 19:39:28 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['CalUtil'])
    env.Tool('addLibrary', library = env['gaudiLibs'])
    env.Tool('identsLib')
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('xmlBaseLib')
def exists(env):
    return 1;
