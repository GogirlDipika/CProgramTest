pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck --platform=win64 --inconclusive --enable=all --xml-version=2 --xml cppcheck.xml'
		    
		// Publish the results using the CppcheckPublisher plugin
        	publishCppcheck pattern: 'cppcheck.xml', enabled: true, threshold: 4, ignoreBlankFiles: true
            }
        }
        stage('Quality gate') {
            steps {
			script{
				sleep 10
				def results = readFile('cppcheck.xml')
          			def errors = results.findAll { it.severity == 'error' }
          			def warnings = results.findAll { it.severity == 'warning' }
          			if (errors.size() > 0 || warnings.size() > 0) {
					error "Pipeline aborted due to quality gate failure: ${errors} errors and ${warnings} warnings"
            				currentBuild.result = 'FAILURE'
				}
			}
		}
        }
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}
