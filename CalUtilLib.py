#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/CalUtilLib.py,v 1.4 2011/11/12 00:46:41 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['CalUtil'])
    env.Tool('identsLib')
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('addLibrary', library = env['gaudiLibs'])
    env.Tool('xmlBaseLib')
def exists(env):
    return 1;
