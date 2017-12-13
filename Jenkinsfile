pipeline {
	agent { node { label 'master' } }
	stages {
		stage('Analysis') {
			steps {
                sh 'doxygen && cd doc/latex && make'
                sh 'rm -rf /usr/local/jenkins/exports/hume/docs/*'
                sh 'cp doc/latex/refman.pdf /usr/local/jenkins/exports/hume/docs/'
                sh 'cp -r doc/html /usr/local/jenkins/exports/hume/docs/web'
			}
		}

        stage('Build') {
            parallel {
                stage('FreeBSD') {
                    agent { node { label 'freebsd' } }
                    steps {
                        sh 'rm -rf build; mkdir build; cd build; cmake ..; make clean; make; mv libhume.a ../libhume-freebsd.a'
                        archiveArtifacts(artifacts: 'libhume-freebsd.a', fingerprint: true)
                    }
                }

                stage('Linux') {
                    agent { node { label 'linux' } }
                    steps {
                        sh 'rm -rf build; mkdir build; cd build; cmake ..; make; mv libhume.a ../libhume-linux.a'
                        archiveArtifacts(artifacts: 'libhume-linux.a', fingerprint: true)
                    }
                }

                stage('MinGW') {
                    agent { node { label 'mingw' } }
                    steps {
                        sh 'rm -rf build; mkdir build; cd build; cmake -DCMAKE_TOOLCHAIN_FILE=../MinGW_toolchain.cmake ..; make; mv libhume.a ../libhume-mingw.a'
                        archiveArtifacts(artifacts: 'libhume-mingw.a', fingerprint: true)
                    }
                }
            }
        }
	}
}
