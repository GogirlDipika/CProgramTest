



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
            }
        }
        stage ('Quality gate') {
            steps {
                sleep 10
                def qg = readFile('cppcheck.xml')
                def errors = qg.scanFor('//error').size()
                def warnings = qg.scanFor('//warning').size()

                if (errors > 0 || warnings > 0) {
                    error "Pipeline aborted due to quality gate failure: ${errors} errors and ${warnings} warnings"
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

       



